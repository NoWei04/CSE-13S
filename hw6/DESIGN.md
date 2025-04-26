Design doc Jacob Wei

For the score letter function I will loop over the array of pointers
and search each pointer (word) for the desired letter. This will likely
have me use a nested for loop to search the entire array for the desired 
letter. A counter will also be implimented and will increase every time
the letter is found

For the score word function I will determine how useful a word is, depending on the variety of letters it uses.  

For the filter vocab gray function I will go through the arrayand skip 
any words that do not have the desired letters or have them at the specified
position. I will also impliment a counter that increases whenever this condition is met.

For the filter vocab yellow function I will impliment a similar approach to the previous
function. If the letter is in the word but not at the specified position, then the counter
will increment by one if the condition is met.

For the filler vocab green function will work similarly to the previous function but instead, 
it will remove words that dont have the letter at all, and add up the total number
of words that have the letter in it.
