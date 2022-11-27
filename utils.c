/*
 * STUDENTS:    Buda Francesco, Ceredi Tommaso, Maglia Danilo, Severi Tommaso
 * DATE:    	15/11/2021
 * FILE:        utils.c
 * DESCRIPTION: IMPLEMENTATION OF LIBRARY "utils". 
 *              FOR DEFINITION SEE "utils.h"
 * VERSIONE:    1.5
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "utils.h"

// --------INPUT FUNCTIONS--------

void stralloc(char** str){
    char* strtmp = (char*)malloc(sizeof(char) * MAX_STRING_SIZE);
    scanf("%s", strtmp);
    *str = (char*)malloc(sizeof(char) * strlen(strtmp) + 1);
    if(str == NULL){
        exit(1);
    }
    strcpy(*str, strtmp);
    free(strtmp);
}

void fstralloc(char** str, FILE* file){
    char* strtmp = (char*)malloc(sizeof(char) * MAX_STRING_SIZE);
    fgets(strtmp, MAX_STRING_SIZE, file);
    int lung = strlen(strtmp);
    strtmp[lung]='\0';
    *str = (char*)malloc(sizeof(char) * lung + 1);
    if(str == NULL){
        exit(1);
    }
    strcpy(*str, strtmp);
    free(strtmp);
}

void flushStdin(){
    int c;
    do {
        c = getchar();
    } while(c != '\n' && c != EOF);
}

// --------ESCAPE SEQUENCE FUNCTIONS--------
void initEscapeSequence(){
    #ifdef NEED_COLOR_FIX
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        if(handle != INVALID_HANDLE_VALUE){
            DWORD mode =  0;
            if (GetConsoleMode(handle, &mode)) {
                mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                SetConsoleMode(handle, mode);
            }
        }
    #endif
}

void clearScreen(){
    printf("%s", CLEAR_SCREEN);
    printf("%s", RESET_CURSOR);
}

// --------CURSOR FUNCTIONS--------

void moveCursor(int x, int y){
    printf("%s", MOVE_CUR(x,y));
}
void moveCurUp(int y){
    printf("%s", MOVE_CUR_UP(y));
}
void moveCurDown(int y){
    printf("%s", MOVE_CUR_DOWN(y));
}
void moveCurRight(int x){
    printf("%s", MOVE_CUR_RIGHT(x));
}
void moveCurLeft(int x){
    printf("%s", MOVE_CUR_LEFT(x));
}
void saveCurPos(){
    printf("%s", SAVE_CUR_POS);
}
void restoreCurPos(){
    printf("%s", RESTORE_CUR_POS);
}

// --------COLOR FUNCTIONS--------

void setColor(char* color){
    printf("%s", color);
}

void resetColor(){
    setColor(CON_RESET);
}

/*
    Description:
        Function that prints a colored message
    Arguments:
        char*: color of the message
        char*: contenuto of the message
*/
void coloredMessage(char* color, char* message){
    setColor(color);
    printf("%s", message);
    resetColor();
}

// --------RANDOM GENERATION FUNCTIONS--------

/*
    Description:
        Function that initializes the random generation
        numbers by setting the seed to time(NULL).
*/
void initRandom(){
    srand(time(NULL));
}

/*
    Description:
        Function that generates a random number in the
        specified range.
    Arguments:
        int min = minimum of range
        int max = maximum of the range
    Returns:
        int: Random number generated
*/
int randomIntRange(int min, int max){
    if(min > max){
        int tmp = max;
        max = min;
        min = tmp;
    }
    return (rand() % (max - min + 1)) + min;
}

// --------ARRAY FUNCTIONS--------

/*
    Description:
        Function that checks if an integer exists
        into the given array
    Arguments:
        int * v = array to check for
        int n = number to search for
        int size = size of the array
    Returns:
        true = number exists
        false = number does not exist
*/
bool existsInt(int* v, int n, int size){
    for(int i = 0; i < size; i++){
        if(v[i] == n){
            return true;
        }
    }
    return false;
}

/*
    Description:
        Function that checks if a float exists
        in the past array
    Arguments:
        float * v = array to check for
        float n = number to search for
        int size = size of the array
    Returns:
        true = number exists
        false = number does not exist
*/
bool existsFloat(float* v, float n, int size){
    for(int i = 0; i < size; i++){
        if(v[i] == n){
            return true;
        }
    }
    return false;
}

/*
    Description:
        Function that prints an array of integers
    Arguments:
        int * v = array to print
        int size = number of elements in the array

*/
void stampaVettoreInt(int* v, int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf(" %d ", v[i]);
    }
    printf("]\n");
}

/*
    Description:
        Function that prints an array of floats
    Arguments:
        float * v = array to print
        int size = number of elements in the array
*/
void stampaVettoreFloat(float* v, int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf(" %f ", v[i]);
    }
    printf("]\n");
}

/*
    Description:
        Function that prints a loading bar
    Arguments:
        int perc = percentage of the loading bar
*/
void progress(int perc){
    int currentProgress = 0;
    initRandom();

    while(currentProgress != 100){
        currentProgress = perc;
        if(currentProgress > 100){
            currentProgress = 100;
        }
        printf("\r");
        for(int i = 0; i < currentProgress; i++){
            setColor(COLOR_GREEN);
            PRINTBAR(BAR_FULL);
            resetColor();
        }
        for(int i = 0; i < (100 - currentProgress); i++){
            PRINTBAR(BAR_EMPTY);
        }
        printf(" %d%c", currentProgress, 37);
        sleep(100);
    }
    setColor(COLOR_GREEN);
    printf("\nConnesso con successo!\n");
    resetColor();
    sleep(300);
}