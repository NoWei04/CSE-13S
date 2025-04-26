Design Doc Jacob Wei

For the score_guess function, I will first allocate
memory for my variables,those being an arrays to track the guessed
letters and the word to guess. As I iterate through the guesses, if the 
guess is correct, I will set the result to g and iterate through the guess
again. If the letter is correct but in the wrong place, I will put a y
and if its completely wrong, there will be an x. For 6 turns, if   
the whole result is gs the funciton will return true. Otherwise,
false will be returned.

The valid guess function will use a linear search to compare the guesses
and the secret word to determine if the guess is valid. To evaluate the
words, I will use strcmp and return true if a match is found and false 
otherwise. To accomodate for edge cases, the function will automatically
return true if the word count is already guessed.

The load vocab function will read a file that contains len-5 words and 
iterate through it using a buffer. As I loop over the file,
I will allocate memory and store the words and guesses using malloc
and strdup, then free any pointers or allocated memory and close the
file to prevent memory leaks

The free vocab function will free all the memory in the vocab array
and its strings. I will simply loop over the array, then free the array.


