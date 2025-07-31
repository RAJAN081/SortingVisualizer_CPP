# 🎮 SortingVisualizer_CPP

A **real-time sorting algorithm visualizer** written in **C++ using SDL2**.  
This tool lets you **see how sorting algorithms work step-by-step**, with animated bars and keyboard controls — like watching DSA come alive 💡.

---

## 📸 Demo Preview

![Demo](screenshots/demo.gif)

---

## 📚 What It Does

This visualizer graphically displays how sorting algorithms arrange elements.  
It:
- Uses vertical bars to represent array elements
- Highlights comparisons, swaps, and sorted positions
- Responds to keyboard inputs to trigger different sorting techniques

---

## 🧠 Sorting Algorithms Included

| Key | Algorithm        |
|-----|------------------|
| `0` | Shuffle Array    |
| `1` | Selection Sort   |
| `2` | Insertion Sort   |
| `3` | Bubble Sort      |
| `4` | Merge Sort       |
| `5` | Quick Sort       |
| `6` | Heap Sort        |
| `q` | Quit Application |

---

## 🛠 Dependencies

You'll need the following tools/libraries:

| Tool     | Version        | Required For          |
|----------|----------------|------------------------|
| `g++`    | v6.3+ (MinGW)  | Compilation            |
| `SDL2`   | v2.0.22        | Graphics & rendering   |
| `SDL2main` | bundled in SDL | Entry-point for SDL apps |

---

## 🧰 Setup Instructions (Windows)

### 1. Download SDL2
From: [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php)

Unzip it, and copy the following:
- Include path: `SDL2-2.0.22/include`
- Lib path: `SDL2-2.0.22/lib`
- Runtime: Copy `SDL2.dll` to your project folder

---

### 2. Compile the Project

```bash
g++ main.cpp common_visuals.cpp sorting_algos/*.cpp ^
 -IE:\SDL2-2.0.22\include ^
 -LE:\SDL2-2.0.22\lib ^
 -lmingw32 -lSDL2main -lSDL2 -o SortVisualizer
