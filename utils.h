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
