/*
** EPITECH PROJECT, 2023
** iter_tools.c
** File description:
** Iterating the list
*/

#include "../../include/linked_lists_utils.h"

void **list_export(l_list *l, void *(*transform)(void *))
{
    void **export;
    size_t i = 0;
    l_elem *e;

    if (l->len == 0)
        return (NULL);
    export = malloc(sizeof(char *) * (l->len + 1));
    if (export == NULL)
        return (NULL);
    e = l->first;
    while (i < l->len){
        if (transform == NULL)
            export[i] = e->content;
        else
            export[i] = transform(e->content);
        e = e->next;
        i ++;
    }
    export[l->len] = NULL;
    return (export);
}

void list_import(l_list *l, void **data)
{
    size_t i = 0;
    l_elem *e = l->first;

    while (i < l->len){
        e->content = data[i];
        e = e->next;
        i ++;
    }
}

void list_iter(l_list *l, void(*func)(void *, void *), void *data)
{
    l_elem *e = l->first;

    while (e != NULL){
        (*func)(e->content, data);
        e = e->next;
    }
}

ssize_t list_first_fulfil(l_list *l, int(*func)(void *, void *), void *data)
{
    l_elem *e = l->first;
    size_t i = 0;

    while (e != NULL){
        if (func(e->content, data))
            return (i);
        e = e->next;
        i ++;
    }
    return (-1);
}

size_t list_count_fulfil(l_list *l, int(*func)(void *, void *), void *data)
{
    l_elem *e = l->first;
    size_t count = 0;

    while (e != NULL){
        if (func(e->content, data))
            count ++;
        e = e->next;
    }
    return (count);
}
