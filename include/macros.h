/*
** EPITECH PROJECT, 2024
** macros.h
** File description:
** Define macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

    #define ABS(num)    ((num >= 0) ? num : -num)
    #ifndef MAX
        #define MAX(n1, n2) ((n1 >= n2) ? (n1) : (n2))
    #endif
    #ifndef BUFFER_SIZE
        #define BUFFER_SIZE 1024
    #endif
    #ifndef OPEN_MAX
        #define OPEN_MAX 128
    #endif
#endif
