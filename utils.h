/*
 * STUDENTS:    Buda Francesco, Ceredi Tommaso, Maglia Danilo, Severi Tommaso
 * DATE:        11/15/2021
 * FILE:        utils.h
 * DESCRIPTION: INTERFACE FOR THE "utils" LIBRARY. THIS HEADER
 *              CONTAINS DEFINITIONS OF FUNCTIONS THAT OFTEN HAPPEN
 *              TO USE IN DIFFERENT PROGRAMS.
 *              ALSO THE HEADER DEFINES MACROS TO IMPROVE
 *              THE PORTABILITY OF THE VARIOUS PROGRAMS AND DEFINES OF THE MACROS
 *              FOR COLORS.
 * VERSION:     1.5
 */

#ifndef GROUP_UTILS_H // Include guard
    #define GROUP_UTILS_H
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    // PROBABILITY MACROS
    #if defined __linux__ || defined __APPLE__ // If compiles in linux or macos
        #include <unistd.h>
        #define sleep(x) usleep( x * 1000 ); // Milliseconds macros fo sleep (usleep works in microseconds)
        #define BAR_FULL  "\u2588"
        #define BAR_EMPTY "\u2591"
        #define PRINTBAR(x) printf("%s", x)
    #elif _WIN32 // If compiles on windows
        #include <windows.h>
        #define sleep(x) Sleep(x)
        #define BAR_FULL  219
        #define BAR_EMPTY 176
        #define PRINTBAR(x) printf("%c", x)
    #endif

    // CURSOR MOVEMENT MACROS
    #define MOVE_CUR(x,y) "\033["#x";"#y"H"
    #define MOVE_CUR_UP(y) "\033["#y"A"
    #define MOVE_CUR_DOWN(y) "\033["#y"B"
    #define MOVE_CUR_RIGHT(x) "\033["#x"C"
    #define MOVE_CUR_LEFT(x) "\033["#x"D"

    #define SAVE_CUR_POS "\033[s"
    #define RESTORE_CUR_POS "\033[u"

    #define CLEAR_SCREEN "\033[2J"
    #define RESET_CURSOR "\033[H"

    // COLOR MACROS
    #define CON_RESET "\033[0m"
    #define COLOR_GREEN "\033[32m"
    #define COLOR_BLACK "\e[0;30m"
    #define COLOR_RED "\e[0;31m"
    #define COLOR_YELLOW "\e[0;33m"
    #define COLOR_BLUE "\e[0;34m"
    #define COLOR_MAGENTA "\e[0;35m"
    #define COLOR_CYANO "\e[0;36m"
    #define COLOR_WHITE "\e[0;37m"

    #ifndef MAX_STRING_SIZE
        #define MAX_STRING_SIZE 100
    #endif
