#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list

ll_text *append_text(ll_text *list, char *text) {
   ll_text *node = malloc(sizeof(ll_text));
   node -> text = strdup(text);

   if(!node -> text){
      free(node);
      return NULL;}

   node -> next = NULL;

   if(list == NULL){
      return node;}
   
   ll_text *i = list;
   while(i -> next != NULL){
      i = i -> next;}

   i -> next = node;
   return list;
}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
  int len = 0;

  while(list != NULL){
     len++;
     list = list -> next;}

  return len;
}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {
  ll_text *node = malloc(sizeof(ll_text));
  node -> text = strdup(text);
  node -> next = NULL;
  int i = 0;
  
  if (position == 0){
    node -> next = list;
    return node;}  
   
  ll_text *j = list;
  
  while(j != NULL && i < position -1){
    j = j -> next;
    i++;}

  if(j == NULL){
    free(node -> text);
    free(node);
    return list;}

  node -> next = j -> next;
  j -> next = node;
  return list;
}

// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {
  if(list == NULL){
     return list;}
  
  ll_text *current = list;
  
  if(position == 0){
     list = list -> next;
     free(current -> text);
     free(current);
     return list;}

  for(int i = 0; i < position - 1 && current != NULL; i++){
     current = current -> next;}
  
  if(current == NULL || current -> next == NULL){
     return list;}

  ll_text *temp = current -> next;  
  current -> next = temp -> next;
  free(temp -> text);
  free(temp);
  return list;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {
  ll_text *current = list;
  
  for(int i = 0; i < position && current != NULL; i++){
     current = current -> next;}  
  
  if(current == NULL){
     return list;}
  
  free(current -> text);
  current -> text = strdup(text);  
  
  return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {
   ll_text *node = malloc(sizeof(ll_text));
   if (list == NULL){
      return NULL;}

   node -> text = strdup(list -> text);
   if(node -> text == NULL){
      free(node);
      return NULL;}
   
   node -> next = duplicate_ll_text(list->next);
   return node;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}

// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {
  ll_text_stack *node = (ll_text_stack *)malloc(sizeof(ll_text_stack));

  node -> lines = duplicate_ll_text(stack -> lines); 

  if(!node -> lines){
     free(node);
     return NULL;}

  node -> next = stack;
  return node;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {
  ll_text_stack *empty_stack = malloc(sizeof(ll_text_stack));

  empty_stack -> lines = NULL;
  empty_stack -> next = stack;

  return empty_stack;
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
  if(stack == NULL){
  return stack;}

  ll_text_stack *top = stack;
  stack = stack -> next;

  free(top -> lines);
  free(top);
  return stack;
}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
