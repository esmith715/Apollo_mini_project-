This mini project is my base understanding of a learning machine. How it works is when you first start up the program you will be prompted to ask a question, after typing in your prompt it will be converted to 
all lowercase which will make it easier for the code to understand and take up less space in the memory file. It will then take your prompt and run it through the memory file to see if there is an answer to the prompt given.
If the prompt is found the code will look to the right of it past the ":" and output the string that is there which is the answer, if the prompt was not found in the memory file the code will retrun with a question asking you
if you might know the answer to your own prompt. There will be two options (yes/ no) if you respond with yes, you will then be able to type in the answer and the code will then append both the original prompt you typed and the 
newly typed answer separated by a ":" to the memory file. Then the next time you boot up the program you can type in the prompt and it will have an answer to output. If you were to respond with no it will then send you back to 
the beginning and ask you to input a question.

What I want to improve for later:
1. if the user types no they do not have an answer to their prompt, the code will then take that prompt and append it to a new file for me or someone who has access to go through and find an answer to that prompt and then
   take that prompt and answer and add it to the memory file
2. See if there is any way to make the code look for keywords or similar words so that if maybe someone asks a question it already has in the memory but in a different way it can output the answer and not take up more space
   by creating a new question and answer
