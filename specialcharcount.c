/*
 * specialcharcount.c - this file implements the specialcharcount function.
 * Alan Ta
 * 819357091
 * cssc2363
 * CS570 Summer
 * Program 0: Letter and character frequency counter
 */


#include <stdio.h>
#include "count.h"
char filelist[1000][256];


// A function to find all the .txt files in a given directory and stores them in an array and returns the number of valid txt files
int storeFileList(char *path) {
    int i = 0;
    // Opens up a directory stream and uses the "path" to access the data directory
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        // Begins reading the contents of the directory, and if valid, will copy the txt file into a 2D array
        while ((dir = readdir(d)) != NULL) {
            size_t len = strlen(dir->d_name);
            if (len > 4 && strcmp(dir->d_name + len - 4, ".txt") == 0) {
                strcpy(filelist[i], dir->d_name);
                i++;
            }

        }
        closedir(d);
    }
    // Closes the directory and returns the number of correct txt files
    return i;
}

// Opens and reads all txt files stored in filelist array and increments the appropriate character
void specialcharcount(char *path, char *filetowrite, long charfreq[])
{
    int m = 0, n = 0, errnum = 0, k = 0;
    FILE *fptr;
    k = storeFileList(path);
    chdir(path);
    for(m; m != k; m++) {
        fptr = fopen(filelist[m], "r");
        if (fptr != NULL) {
            // Compares the file character to the special character and increments the appropriate character frequency
            while ((n = fgetc(fptr)) != EOF) {
                if(n == ',')
                    charfreq[0]++;
                if(n == '.')
                    charfreq[1]++;
                if(n == ':')
                    charfreq[2]++;
                if(n == ';')
                    charfreq[3]++;
                if(n == '!')
                    charfreq[4]++;
            }
            fclose(fptr);
        } else if (fptr == NULL) {
            printf("File does not exist\n");
            errnum = errno;
            fprintf(stderr, "Value of errno is: %d \n", errnum);

        }
    }
    // Creates a pointer to a file with write privileges and begins writing each letter and its frequency
    FILE *ResultFile = fopen(filetowrite, "w");
    fprintf(ResultFile," \n character -> frequency \n \n");
    for(int i = 0; i < 5; i++)
    {
        switch(i)
        {
            case 0:
                fprintf(ResultFile,", -> %d\n", charfreq[i]);
                break;
            case 1:
                fprintf(ResultFile,". -> %d\n", charfreq[i]);
                break;
            case 2:
                fprintf(ResultFile,": -> %d\n", charfreq[i]);
                break;
            case 3:
                fprintf(ResultFile,"; -> %d\n", charfreq[i]);
                break;
            case 4:
                fprintf(ResultFile,"! -> %d\n", charfreq[i]);
                break;
        }
    }
    fclose(ResultFile);
}
