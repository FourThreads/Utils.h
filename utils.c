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