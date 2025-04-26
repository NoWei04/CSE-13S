Design Doc Jacob Wei

Designing the main interaction loop commands:

Before designing the functions for the loops, I will prepare data strctures by 
allocating memory for the table and create structs for the linked lists and hash
map.

First, I'll need a function to compute the hash value of a given string, which
would ideally minimize collisions. This function will iterate through the string,
shift the current hash and add the char's ascii value. Afterwards, I'll reduce the
hash value so it fits within our buckets.

Second, I'll load the data from the tsv file and process its contents with the 
hash function.

Starting with the add funciton, I'll prompt the user for input. Then I'll 
get the head of the linked list and go through the list to see if the name exists.
If it does, I'll delete the old entry and add the new one in. 

For the lookup function, I will access the bucket and retreive the head of the linked
list. Then I will iterate through it until I find the email, then return it.

The delete function will locate the email using the hash value and iterate through
the linked list until the matching email is found. It will remove the node from the
bucket and free the memory. Edgecases will be implimented for the head and tail nodes

The list function will iterate over everything in the hash table and print out all
the customer information. 

The save function will update the .tsv file with the new current version of the hash
table. 

The quit function will clear all the allocated memory and exit the program and set 
all the pointers and nodes to null. 
