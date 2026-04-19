# Page Replacement Simulator

This project implements core Operating System page replacement algorithms in C++.

## Algorithms Implemented
- FIFO (First In First Out)
- LRU (Least Recently Used)
- Optimal

## Features
- User input for page reference string and frame size
- Step-by-step simulation
- Page fault calculation

## How to Run
1. Compile:
   g++ main.cpp -o simulator
2. Run:
   ./simulator

## Example Input
Pages: 7 0 1 2 0 3 0 4  
Frames: 3

## Output
Displays step-by-step frame allocation and total page faults.
