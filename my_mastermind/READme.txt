# Welcome to My Mastermind
***

## Task
Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.
The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.
You must read the player's input from the standard input.
Your program will also receive the following parameters:
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

## Description
This project is about implementing the Mastermind game in C and compiling it using `make`. 
The program takes in two command line arguments `-c` for secret code (4 digits) and `-t` for attempts.
By default, `-c` will be generated randomly if none is provided, while `-t` defaults to `10`.
In order to collect the arguments, the `main` function of the program looks for the occurrence of a dash (`-`) in the arguments,
then checks if the following character is `c` or `t`. Getting a `c`, the program reads the next key and parses it as the secret code.
If it gets a `t`, it parses the next value to get the number of attempts. These values are then passed into `my_mastermind` function for further execution.

## Installation
No Installation need
Use makefile to compile

## Usage
Pass in your secret four digit code in the range 0-7 code and number of attempts as commandline argument using -c and -t.
In the absence of that, the program randomly generates a code and set the number of attempts as 10.
The program takes the code and ask a user to guess the code for a number of the given attempts. 
If a user gets the code right or hols CTRL+D, the program ends.
When a user passes a wrong input (code not a digit or number of codes not equals to four), the program keeps asking
for a correct input and does not count them as a round.

Have FUN!!!!
./my_project argument1 argument2
```

### The Core Team
OGTL Trainee
Martins Olu Ake


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
