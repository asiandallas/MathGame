# MathGame

Simple math game that utilizes queue data structure and threads. 

This program will ask the user to answer math questions (add, sub, mult, div).
The queue will have 3 questions before the game starts. After the game starts, a new question
will be added every 1 second if the level is 5, 2 seconds if the level is 4, .. 5 seconds if the level is 1.
The user will be asked to choose a level from 1 to 5 before the game starts.
A question for the user to answer will be removed from the front of the queue. The user will be asked to answer
the same question until he gives the correct answer. After he gives a correct answer, the next question will be removed from the front of
the queue.

## Compilation
- Compile: `g++ -pthread game.cpp queue.cpp`
- Execution: `./a.out`
