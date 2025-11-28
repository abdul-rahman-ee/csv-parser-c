# CSV Parser

A command-line tool for parsing and analyzing CSV files, written in C.

## Overview

This program reads CSV files and extracts structural information including header names, row counts, column counts, and provides a data preview. Designed as a foundational file I/O project demonstrating string manipulation, memory management, and command-line argument handling in C.

## Features

- Automatic header detection and display
- Row and column counting
- Data preview (first 5 rows)
- Input validation and error handling
- Clean, formatted output

## Build Instructions

### Windows (Visual Studio)
```
1. Open CSV Parser.c in Visual Studio
2. Build → Build Solution (Ctrl+Shift+B)
3. Run with: CSV Parser.exe <filename.csv>
```

### Linux/macOS (GCC)
```bash
gcc -o csv_parser "CSV Parser.c"
./csv_parser sample.csv
```

## Usage
```
./csv_parser <filename.csv>
```

## Example Output
```
=== CSV PARSER RESULTS ===

File: sample.csv.txt
Headers: Name,Age,GPA,Major
Row 1: Essa,20,3.85,Electrical Engineering
Row 2: Sarah,21,3.75,Computer Science
Row 3: Ahmed,19,3.90,Mechanical Engineering

--- Summary ---
Total Rows: 4 (1 header + 3 data rows)
Total Columns: 4
```

## Technical Implementation

- **File I/O**: Uses standard C library functions (`fopen`, `fgets`, `fclose`)
- **String Processing**: Character-by-character parsing for delimiter detection
- **Memory**: Stack-allocated buffers with defined size constraints
- **Error Handling**: Validates command-line arguments and file access

## Author

AbdulRahman — Electrical Engineering Student  
November 2025
