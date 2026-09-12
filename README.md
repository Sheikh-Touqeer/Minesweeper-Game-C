# Minesweeper Game in C

A console-based Minesweeper game developed in C as a programming project. The project demonstrates core programming concepts including arrays, loops, conditional logic, file handling, string processing, and game-state management.

## Features

- 4×4 interactive game board
- 4 configurable mine positions
- Cell selection from 1–16
- Detection of mine locations
- Adjacent-mine counting for safe cells
- Prevention of reopening previously selected cells
- Win and loss detection
- Player name input
- File-based game history
- Search previous game records by player name
- Top 3 player ranking based on recorded wins
- Input validation for board positions and mine placement

## Technologies

- C
- Standard C Library
- File Handling
- Arrays
- Strings
- Conditional Logic
- Loops

## How It Works

At the start of a new game, player names are entered and four mine positions are selected for the 4×4 board.

Players select cells numbered from 1 to 16. If a selected cell contains a mine, the game ends. For a safe cell, the program calculates the number of mines in its surrounding cells and displays that number on the board.

Game information is stored in `minesweeper_log.txt`, allowing previous records to be searched and player rankings to be generated.

## Compile and Run

Using GCC:

```bash
gcc minesweeper.c -o minesweeper
./minesweeper
