/*
* CSV Parser - A command-line tool to parse and analyze CSV files
* Author: AbdulRahman
* Date: November 2025
*
* Description: This program reads a CSV file and extracts:
*   - Total row count
*   - Total column count
*   - Header names
*   - Data preview
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 50
#define PREVIEW_ROWS 5


// Function prototypes
int count_columns(const char* line);
void print_usage(const char* program_name);


int main(int argc, char* argv[]) {
    // Variables we need
    FILE* file;
    char line[MAX_LINE_LENGTH];
    int total_rows = 0;
    int total_columns = 0;

    // Step 1: Check if user provided a filename
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    // Step 2: Try to open the file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Step 3: Read file line by line and count rows
    printf("\n=== CSV PARSER RESULTS ===\n\n");
    printf("File: %s\n", argv[1]);

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Remove the newline character at the end
        int len = (int)strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        total_rows = total_rows + 1;

        // First row tells us number of columns
        if (total_rows == 1) {
            total_columns = count_columns(line);
            printf("Headers: %s\n", line);
        }
        else {
            // Print data rows
            printf("Row %d: %s\n", total_rows - 1, line);
        }
    }

    // Step 4: Print summary
    printf("\n--- Summary ---\n");
    printf("Total Rows: %d (1 header + %d data rows)\n", total_rows, total_rows - 1);
    printf("Total Columns: %d\n", total_columns);

    // Step 5: Close the file
    fclose(file);

    return 0;
}

// Count the number of columns by counting commas + 1
int count_columns(const char* line) {
    int count = 1;  // Start at 1 (first column before any comma)
    int i = 0;

    // Loop through each character in the line
    while (line[i] != '\0') {  // '\0' marks end of string
        if (line[i] == ',') {
            count = count + 1;  // Found a comma, add 1
        }
        i = i + 1;
    }

    return count;
}

// Print the header names from the first line
void print_headers(const char* header_line) {
    // TODO: Implement
}

// Print a single row with formatting
void print_row(const char* line, int row_number) {
    // TODO: Implement
}

// Print usage instructions
void print_usage(const char* program_name) {
    printf("Usage: %s <filename.csv>\n", program_name);
    printf("Example: %s data.csv\n", program_name);
}