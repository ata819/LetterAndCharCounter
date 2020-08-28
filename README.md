A clear, concise and well written README file should be provided. This file should be a detailed description of your code and the logic used through your program. The details in this file should be such that, if you looked at this program in let’s say a year from now, you should be able to understand the execution, logic and algorithms used in this program without reading through the code itself. This file should also contain a description of how to run your program and where to find the desired output. i.e, whether the output is displayed on the terminal or dumped in a file and so on.

Info: 
Alan Ta
819357091
cssc2363
CS570 Summer
Program 0: Letter and character frequency counter

Program Description: A program designed to read txt files given a certain directory with a max size of 1000 files. It retains to separate functions that count either the number of each time a letter(A - Z & a - z) was read or special characters (, . : ; ! ). It will then display the frequency of each letter or character in the following format:

    letter -> frequency

     example:
     A -> 200
     B -> 101
     ... ...
or

    character -> frequency

     example:
     , -> 20
     . -> 11
     : -> 20
     ; -> 11
     ! -> 12 

Files included:


alphabetcount.c

specialcharcount.c

count.h

testalphabetcount.c

testspecialcharcount.c

makefile

How to run:

Enter the appropriate directory where all the files are held.

Warning: Because of the way the program was design, the location of neccesary directories are need. There should be a result and data directory as they are paths the program will use to 1. Gather the data set from (txt files) and 2. place the result.txt. in

:make

:./testalphabetcount 

or

:./testspecialcharcount

The successful execution should present the results in the result directory labed either

result.txt // For letters

specialresult.txt // For characters

It will also print out the results to stdout on screen

Design & Code explaination:

alphabetcount.c - I created to functions in order to create the desired application. The first function 
    
    int storeFileList(char *path){..}
was designed to open up the directory of where the txt files would be in. I used the dirent.h library to open up a directory stream, opendir(),  with the path "../data". With the stream open, I used the readdir() to read the data directory's contents while it was not NULL/empty. As the program would reach each file (regardless if it was a .txt file), I would then check, by getting the length of a file and checking if it had a ".txt" extension. If its length was longer than 4 characters and the last 4 characters were the .txt extension, it would then store the name of the file and increment the fixed 2D array. After all files were read, the directory stream would then close and I returned the number of valid text files.

    void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[]) {..}
This function is where the most work happens. After gathering the correct text files, this function will then count and print the goals of this application.

I had a tough time figuring it out why I keep getting errno:2 when trying to open the files, but I figured it out. I had to change the directory from ../zero to ../data, as the files do exist, but are the program could only open the files in the current directory. So i used chdir() and changed it to the correct path. With the correct path, I created a for loop so I could iterate through the filelist and test each file. I fopen() with the r flag so I could read the contents of the file and used fgetc to fetch a character from the file. I would then check the ascii values of that character, because computer reads numbers and letters are technically assigned to numbers, and if they match the ascii equivalent of a letter, I would then increment the value of that letter
     
    if (n >= 'a' && n <= 'z') {
        alphabetfreq[n - 71]++;
    } else if (n >= 'A' && n <= 'Z') {
        alphabetfreq[n - 65]++;
    } 
To explain, the value of 'A' is 65 in ascii. thus, if 'A' is the alphabetfreq[0], 65 - 65 = 0 thus incrementing the correct letter frequency. 
This frequency increments will continue til all the files in filelist are read and accounted for.
 
Next I created a error catching function. Just in case the opening the file becomes an issue, it will display the errno value to help fix the issue.

Finally I opened a new file, setting the flag to write and passed the frequency totals to filetowrite. The rest of the code is similar to the displayalphabetfreq() [In the testalphabet.c] but uses fprintf() to write to the new .txt file and displays the required format.

    specialcharcount.c
special character count consist of mostly similar code to alphabetcount.c as its requirements are similar.
int storeFileList(char *path) function, the fprintf() to write the frequency to the txt file. The only difference in code is the how I id the correct characters, which is easier and shorter compared to the alphabet letters.

In the specialcharcount(char *path, char *filetowrite, long charfreq[])

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
It's just a set of if statements and increments the matching character.

count.h - just a header file. The used libraries:
    #include <stdio.h> - fopen,fgetc, fprintf
    #include <dirent.h> - Used for directory paths. i.e. opeddir(), readdir()
    #include <string.h> - strcpy, strcmp, strlen 
    #include <unistd.h> -  chdir()
    #include <errno.h> - errno



Possible Improvements/Alternate Designs:

I realized that I did not have to store the the text files in order to total the frequency for the letters and characters. Rather instead, when I was checking if the data was a .txt file, I could have just open the file on the spot and count the letters/characters then. Kinda an oversight by me, as it would have save unused space. Using my fixed 2D array of 1000 is potentially very wasteful, but I was too far along to change up my code. 

In terms of alternate designs, I could have used freopen() and rerouted all of stdout to the result file. By doing this, I wouldn't get any printed result from stdout, rather that would be redirected into the file. I was not sure on the specifics if the program should also print to stdout, so I left this design idea alone. The current program does both and has no issues.