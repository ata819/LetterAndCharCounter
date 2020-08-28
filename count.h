/* charcount.h - This header file include type definitions (including function prototypes) and macros
   used for the programing assignment zero.
 * Alan Ta
 * 819357091
 * cssc2363
 * CS570 Summer
 * Program 0: Letter and character frequency counter
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define ALPHABETSIZE 52     //The total number of alphabetical letter from A - Z and a - z(case sensitive)
#define SPECIALCHARSIZE 5   // The number of these special characters ','   '.'  ';'  ':'  '!'



void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[]);

// A function to find all the .txt files in a given directory and stores them in an array and returns the number of valid txt files
int storeFileList(char *path);

void specialcharcount(char *path, char *filetowrite,  long charfreq[]);

