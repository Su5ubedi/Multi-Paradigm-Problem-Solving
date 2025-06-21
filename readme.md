# Statistics Calculator - Multi-Language Implementation

A simple program that calculates basic statistics (mean, median, mode) implemented in three different programming languages, each demonstrating a distinct programming paradigm.

## Overview

This project implements the same statistical calculations in:
- **C** - Procedural programming paradigm
- **OCaml** - Functional programming paradigm
- **Python** - Object-oriented programming paradigm

## Statistics Calculated

- **Mean**: Average of all integers in the list
- **Median**: Middle value when the list is sorted
- **Mode**: Most frequently occurring integer(s) in the list

## Implementation Details

### C (Procedural)
- Uses arrays and manual memory management
- Separate functions for each calculation
- Direct implementation of sorting and counting algorithms
- Focus on step-by-step procedural logic

### OCaml (Functional)
- Uses immutable lists and higher-order functions
- Leverages `fold`, `filter`, and `map` operations
- No mutable state or side effects
- Emphasizes function composition and recursion

### Python (Object-Oriented)
- Implements `StatisticsCalculator` class
- Encapsulates data and methods within the class
- Uses dictionaries and lists for data manipulation
- Demonstrates OOP principles like encapsulation

## Getting Started

### Prerequisites
- **C**: GCC compiler
- **OCaml**: OCaml compiler (`ocaml` command)
- **Python**: Python 3.x

### Running the Programs

#### C Implementation
```bash
gcc -o statistics statistics.c
./statistics
```

#### OCaml Implementation
```bash
ocaml statistics.ml
```

#### Python Implementation
```bash
python statistics.py
```

## Sample Output

Each implementation produces similar output:
```
Data: [1, 2, 2, 3, 4, 4, 5]
Mean: 3.00
Median: 3.00
Mode(s): [2, 4]
```

## File Structure

```
statistics-calculator/
├── statistics.c     # C implementation (procedural)
├── statistics.ml    # OCaml implementation (functional)
├── statistics.py    # Python implementation (object-oriented)
└── README.md       # This file
```

## Key Features by Language

| Language | Paradigm | Key Features |
|----------|----------|--------------|
| C | Procedural | Manual memory management, arrays, explicit algorithms |
| OCaml | Functional | Immutable data, higher-order functions, no side effects |
| Python | Object-Oriented | Class encapsulation, methods, built-in data structures |