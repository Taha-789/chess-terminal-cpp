# Console Chess Game in C++

This project is a console-based implementation of the game of chess written in C++. It provides a complete two-player experience with proper rule enforcement, including move validation, check and checkmate detection, pawn promotion, and undo functionality.

The program uses file handling to manage board states and allows players to interact through a simple coordinate-based input system.

---

## Features

* Full 8x8 chessboard representation
* Move validation for all standard chess pieces:

  * Pawn
  * Rook
  * Knight
  * Bishop
  * Queen
  * King
* Detection of check and checkmate conditions
* Pawn promotion support
* Undo last move functionality
* File-based state management for moves

---

## How to Run

1. Compile the program using a C++ compiler:

   ```
   g++ main.cpp -o chess
   ```

2. Run the executable:

   ```
   ./chess
   ```

3. Ensure that the `BOARD.txt` file is present in the same directory as the executable.

---

## How to Play

* The game is played between two players:

  * Player 1 uses uppercase letters (P R N B Q K)
  * Player 2 uses lowercase letters (p r n b q k)

* Moves are entered using row and column indices:

  ```
  Example: 6 4
  ```

* First enter the source position, then the destination position when prompted.

* The game enforces legal moves and prevents moves that would leave a king in check.

---

## File Structure

* `main.cpp` — contains the full implementation of the game logic
* `BOARD.txt` — initial board configuration
* `previousMove.txt` — stores the previous board state for undo
* `currentMove.txt` — stores the current board state

---

## Technical Overview

This project demonstrates:

* Dynamic memory management using pointers
* Modular programming with multiple validation functions
* Implementation of rule-based game logic
* Use of file input/output for persistent state handling

---

## Author

Muhammad Taha Qureshi
