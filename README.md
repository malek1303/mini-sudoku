# Mini-Sudoku (3x3)

A lightweight, console-based puzzle game written in C++. This project implements a simplified version of Sudoku on a 3x3 grid. The objective is to fill the entire board with numbers from 1 to 3 without repeating a number in any row or column.

## 🚀 Features

* **Dynamic Board Rendering:** Draws a clean ASCII interface with coordinate mapping (`a-i`).
* **Randomized Starts:** Uses `srand` and `time` to seed two random numbers at the beginning of every game to ensure a unique challenge.
* **Input Validation:** Robust checking for valid positions (ASCII-based mapping) and ensuring cells aren't overwritten.
* **Win/Loss Logic:** Real-time checking of Sudoku constraints after every move.

## 🛠️ How to Run

Since the project uses standard C++ libraries, you can compile it using `g++` on your Arch Linux terminal (or any GCC-supported environment).

1.  Clone this repository or save the file as `main.cpp`.
2.  **Compile:**
    ```bash
    g++ main.cpp -o mini_sudoku
    ```
3.  **Run:**
    ```bash
    ./mini_sudoku
    ```

## 🎮 How to Play

The board is displayed with letters `a` through `i` representing the positions:

```text
 a | b | c
---+---+---
 d | e | f
---+---+---
 g | h | i
```

* **Goal:** Fill all spaces with numbers 1, 2, or 3.
* **Constraint:** You lose if you place the same number twice in the same row or column.
* **Win:** Fill the entire board without violating the constraints.

## 🧠 Technical Implementation

* **Memory Efficiency:** The board is represented as a 1D array `char board[9]`, which simplifies indexing and memory overhead.
* **Coordinate Mapping:** User input is converted from characters to array indices using ASCII math: `play = pos - 'a'`.
* **Win/Loss Condition:** The `checklose()` function utilizes a 2D lookup table containing all possible winning/losing combinations for rows and columns.

> [!NOTE]
> This version focuses on the 3x3 grid logic. Unlike standard 9x9 Sudoku, this variant does not require sub-grid (box) checks, making it a fast-paced logic game.

## 📈 Future Enhancements

- [ ] Implement a **Diagonal Check** mode for increased difficulty.
- [ ] Add a **Best Time** tracker using the `<chrono>` library.
- [ ] Port the logic to an **embedded platform** (like the ATmega32) using an LCD for the display.
