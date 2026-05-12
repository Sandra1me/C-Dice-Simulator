# Dice Simulator (C)

A simple yet robust C program that simulates rolling dice with different numbers of faces (6, 12, or 20).
This project includes input validation, modular design, and statistical analysis of dice rolls.

## Installation

Clone the repository and compile the program using a C compiler (e.g., GCC):

gcc virtualDice.c -o virtualDice

Run the program:

./virtualDice

## Features

- Select dice type (D6, D12, D20)
- Roll multiple dice at once
- Input validation for all user inputs
- Random number generation using rand()
- Statistics per roll:
   - Total sum
   - Average value
   - Maximum value
   - Frequency of each face
- Repeat rolls interactively

## Usage

Example interaction:

```c
Select the number of faces of the dice: 
1- 6 faces 
2- 12 faces 
3- 20 faces 
Type 1, 2 or 3: 1 

How many dice do you want to roll? 3 

Obtained number in dice number 1 is: 4 
Obtained number in dice number 2 is: 2 
Obtained number in dice number 3 is: 6 

--- Statistics for this roll --- 
Total number of dice rolled is: 3 
Maximum number obtained is: 6 
The sum of all the dice is: 12 The average value obtained from all the dice is: 4.00 

--- Frequency --- 
Number 1 has appeared 0 times. 
Number 2 has appeared 1 times. 
...
```

## Project Structure

The program is modular and divided into functions:

- rollDice(int faces)
   - Generates a random number between 1 and the number of faces.
- getValidFaces()
   - Displays a menu and ensures valid user input.
- numberDice()
   - Asks the user how many dice to roll and validates input.
- askRepeat()
   - Prompts the user to continue or exit.


## Possible Improvements

- Use dynamic memory allocation (malloc, calloc) instead of VLAs
- Add histogram visualization for frequencies
- Simulate large numbers of rolls (Monte Carlo simulation)
- Export results to a file
- Add support for custom dice (user-defined faces)


## Contributing

This is a learning project, but suggestions and improvements are welcome.
Feel free to fork the repository and experiment with new features.

## License

This project is open source and available under the [MIT License](https://choosealicense.com/licenses/mit/).
