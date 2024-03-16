/*
** EPITECH PROJECT, 2023
** linked_lists_utils.h
** File description:
** Linked list utils
*/

#ifndef LINKED_LISTS_UTILS_H_
    #define LINKED_LISTS_UTILS_H_

    #include <stdlib.h>
    #include "my.h"

void initialize_elem(l_elem *e, void *content);
l_elem *create_elem(void *content);
void delete_elem(l_elem *e, void(*del)(void *));
void destroy_elem(l_elem *e, void(*del)(void *));
void destroy_list(l_list *l);
l_elem *list_get_last(l_list *l);
l_elem *list_get_index_elem(l_list *l, size_t index);
l_list *create_list(void(*del)(void *));
size_t list_len(l_list *l);

#endif
