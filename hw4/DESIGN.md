Design Document HW4

Fn 1:
This function will take in input text and use a linked list to put the text together.
If the list is empty, a new node will be returned as the new start of the list, otherwise
it will append text to the last node.

Fn 2:
At the specified position, the pointer will go to the desirable location in the list.
Before I do any of this, its important to create a stack and append the text to copy at
the top of the stack

Fn 3:
This function will do the same thing as the previous one, but pop/delete the text from the 
top of the stack.If I deleted the last element in the stack, the fn will return NULL.

Fn 4:
This will simply copy the element at the top of the stack and replace wherever desired.

Fn 5:
This will iterate through the original list, allocate more memory for the duplicate and 
recreate it through the same process of linking nodes together.

Fn 6:
Text length will simpily return the length of the list.

Fn 7:
I can reuse the duplicate function here to point back to top of the stack.

Fn 8:
Here I can just create and append an empty stack to a desirable stack that already exists.

Fn 9: 
I'll remove the top element of my stack and clear my memory so there isnt any leakage. 
After this, I will return the new top element. 
