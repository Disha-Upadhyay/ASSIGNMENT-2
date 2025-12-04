# ASSIGNMENT-2
# Car Dodger – Console Game in C  
### Original Version + Modified Version Documentation

## ANALYSIS

Car Dodger is a simple lane-switching game where the player avoids falling obstacles.  
The gameplay takes place in **3 vertical lanes** inside the console window.

Both versions use:

- `conio.h` for non-blocking keyboard input  
- `windows.h` for cursor movement and color  
- A flicker-free approach using `SetConsoleCursorPosition()`  

---

# 🕹️ Original Version (Before Modification)

### ✔️ Features
- Player moves between **3 lanes**
- Falling obstacle appears in random lane
- **Score system** (increases every time obstacle resets)
- **Speed increases** as score increases
- Uses a separate **playGame()** function
- Obstacle handled using a **struct**
- Game Over screen includes:
  - Final score
  - Encouragement message (if score ≥ 20)
  - Option to **Restart (R)** or **Quit (Q)**

### ✔️ Controls
| Key | Action |
|-----|--------|
| ← | Move left |
| → | Move right |

### ✔️ Architecture
- `Obstacle` struct  
- Modular code: `playGame()`, `main()`  
- Clean game loop with scoring & restart logic

---

# Modified Version (Updated Game)

The modified code adds sound effects, new visuals, and simplifies game logic.

## ✨ New Additions
# Car Dodger – Modified Version README

The updated version introduces audio, visual improvements, and simplified game mechanics.

## 📌 Overview

The modified version of Car Dodger is based on the original game but includes several key changes:

- Addition of **background music** and **crash sound effects**
- Visual changes to player and obstacle characters
- Removal of scoring, restart logic, and dynamic difficulty
- Simplified structure by removing the `Obstacle` struct and `playGame()` function
- 
## 🔊 1. Audio System (New Feature)

### ✔ Background Music Added  
Plays continuously during gameplay:
```c
PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);
