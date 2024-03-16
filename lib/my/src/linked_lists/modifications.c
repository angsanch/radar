/*
** EPITECH PROJECT, 2023
** modifications.c
** File description:
** Modify elements
*/

#include "../../include/linked_lists_utils.h"

int list_append(l_list *l, void *content)
{
    l_elem *last = list_get_last(l);
    l_elem *e = create_elem(content);

    if (e == NULL)
        return (0);
    if (last == NULL)
        l->first = e;
    else
        last->next = e;
    l->len ++;
    return (1);
}

int list_push(l_list *l, void *content)
{
    l_elem *e = create_elem(content);

    if (e == NULL)
        return (0);
    e->next = l->first;
    l->first = e;
    l->len ++;
    return (1);
}

int list_insert(l_list *l, size_t index, void *content)
{
    l_elem *e;
    l_elem *prev;

    if (index == 0)
        return (list_push(l, content));
    prev = list_get_index_elem(l, index - 1);
    if (prev == NULL)
        return (0);
    e = create_elem(content);
    if (e == NULL)
        return (0);
    e->next = prev->next;
    prev->next = e;
    l->len ++;
    return (1);
}

int list_pop(l_list *l, size_t index)
{
    l_elem *prev;
    l_elem *deletion;

    if (index == 0){
        list_pop_first(l);
        return (1);
    }
    prev = list_get_index_elem(l, index - 1);
    if (prev == NULL)
        return (0);
    deletion = prev->next;
    prev->next = deletion->next;
    destroy_elem(deletion, l->del);
    l->len --;
    return (1);
}
