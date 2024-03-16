/*
** EPITECH PROJECT, 2024
** cooler_split.h
** File description:
** Only a struct because of coding style
*/

#ifndef COOLER_SPLIT_H_
    #define COOLER_SPLIT_H_

typedef struct coolersplit_context {
    char const *str;
    char const *separators;
    ssize_t word_count;
    char **result;
    size_t offset;
    char on_block;
} splited;

#endif
