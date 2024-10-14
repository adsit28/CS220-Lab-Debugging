/** 
 * ===========================================================
 * Name:
 * Section:
 * Project: Practice debugging lab.
 * ===========================================================
 */

/****************************************************************
 * COMPLETION INSTRUCTIONS:
 *
 * This program should read number from a file and store them in an array.
 * 
 * The program should then (based on the user's selection) check to see
 * if the values are stored in ascending or descending order.
 * 
 * There are errors present in this code you should fix them.
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 1000 /* Max numbers in file */

char DATA_FILE[100] = "";  /* The name of the data file (will be filled in by user) */

int data[MAX_NUMBERS]; /* Array of numbers to search */
int max_count;         /* Number of valid elements in data */

int main(int argc, char** argv) {
    FILE *in_file; /* Input file */
    int i;         /* Keeps track of where we are in the array*/
    int prev;      /* the previous number */
    int max = -999999999;       /* maxinimum value found*/
    int min = 999999999;       /* minimum value found*/
    int mode;      /* 1 = ascending; 2 = descending */
    char line[80]; /* Input line */

    printf("What is the name of the file: ");
    fgets(DATA_FILE, 100, stdin);
    DATA_FILE[strlen(DATA_FILE)-1] = '\0';

    in_file = fopen(DATA_FILE, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error:Unable to open %s\n", DATA_FILE);
        exit(8);
    }

    /*
     * Read in data
     */
    max_count = 0;
    while (1) {
        // Tests to see if the end of the file has been reached
        if (fgets(line, sizeof(line), in_file) == NULL)
            break;

        /* convert number */
        sscanf(line, "%d", &data[max_count]);
        max_count++;
    }

    printf("Enter 1 to check %s for ascending order; 2 for descending; -1 to exit: ", DATA_FILE);
    scanf("%d", &mode);

    if (mode == -1) 
        return 0;

    prev = data[0];      
    i   =  0;
    
    while (1) { 
        
        if (i == max_count && mode == 1) {
            printf("File is sorted in ascending order (min = %d; max = %d)\n", min, max);
            break;
        }

        if (i == max_count && mode == 2) {
            printf("File is sorted in descending order (max = %d; min = %d)\n", min, max);
            break;
        }

        if (mode == 1 && data[i] < prev) {
            printf("Not in ascending order as of index %d. Terminating.\n", i);
            break;
        }

        if (mode == 2 && data[i] > prev) {
            printf("Not in descending order as of index %d. Terminating.\n", i);
            break;
        }

        if (data[i] > max) {
            max = data[i];
        }

        if (data[i] < min) {
            min = data[i];
        }
        
        ++i;

    }

    return 0;
}