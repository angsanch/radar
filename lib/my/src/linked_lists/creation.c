/*
** EPITECH PROJECT, 2023
** basic_list.c
** File description:
** Basic utils
*/

#include <stdlib.h>
#include "../../include/my.h"

void initialize_elem(l_elem *e, void *content)
{
    if (e == NULL)
        return;
    e->next = NULL;
    e->content = content;
}

l_elem *create_elem(void *content)
{
    l_elem *e = malloc(sizeof(l_elem) * 1);

    initialize_elem(e, content);
    return (e);
}

void list_initialize(l_list *l, void(*del)(void *))
{
    l->len = 0;
    l->first = NULL;
    l->del = del;
}

l_list *list_create(void(*del)(void *))
{
    l_list *l = malloc(sizeof(l_list) * 1);

    if (l == NULL)
        return (NULL);
    list_initialize(l, del);
    return (l);
}
