# Terminal Tic-Tac-Toe

This project is a simple console-based Tic-Tac-Toe game written in C++. It supports both Player vs Player and Player vs AI modes. The AI uses layered logic to play competitively, including winning moves, blocking moves, fork prevention, and strong opening strategies.

---

## Features

### Player vs Player
Two human players alternate turns placing X and O on a 3×3 grid. The game checks for wins and ties after every move.

### Player vs AI
The AI plays as O and uses several decision layers:
- Completes winning moves when available
- Blocks the player's winning moves
- Prevents common fork setups
- Prioritizes center, then corners, then edges
- Falls back to the first available square if no strategy applies

### Input Validation
Players cannot select an occupied square. The game prompts again until a valid move is entered.

### Win and Tie Detection
All eight winning combinations are checked after each turn. If the board fills with no winner, the game ends in a tie.

---


## AI Logic Overview

The AI follows this priority order:

1. Win immediately if possible  
2. Block the player's winning move  
3. Prevent fork setups  
4. Take the center  
5. Take a corner  
6. Take an edge  
7. Take the first available square  

This approach creates a strong opponent without using recursion or minimax algorithms.

---

## Requirements

- Obviously a Terminal or command prompt
- If you want to do it the hard way you need a C++ compiler (C++11 or later recommended)

---

## How to Play:
You have 2 options here:
### 1. The Easy Way:
All you have to do is download the latest release!


### 2. The HARD Way (NOT HARD):
Compile using a C++ compiler such as g++
```
g++ main.cpp -o main
```
I Know NOT HARD.

---

#### Have Fun!
