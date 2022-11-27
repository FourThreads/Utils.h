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