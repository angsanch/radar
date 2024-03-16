/*
** EPITECH PROJECT, 2023
** deletion.c
** File description:
** Basic utils
*/

#include <stdlib.h>
#include "../../include/my.h"

void delete_elem(l_elem *e, void(*del)(void *))
{
    if (e == NULL)
        return;
    (*del)(e->content);
    e->next = NULL;
    e->content = NULL;
}

void destroy_elem(l_elem *e, void(*del)(void *))
{
    delete_elem(e, del);
    free(e);
}

void list_delete(l_list *l)
{
    size_t i = 0;
    l_elem *current;

    if (l == NULL)
        return;
    while (i < l->len){
        current = l->first;
        l->first = l->first->next;
        destroy_elem(current, l->del);
        i ++;
    }
    l->len = 0;
    l->first = NULL;
    l->del = NULL;
}

l_list *list_destroy(l_list *l)
{
    list_delete(l);
    free(l);
    return (NULL);
}
