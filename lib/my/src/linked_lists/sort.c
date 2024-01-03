/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** Sort the list
*/

#include "../../include/linked_lists_utils.h"

static l_elem *elem_advance(l_elem *e, size_t steps)
{
    size_t i = 0;

    while (i < steps) {
        e = e->next;
        i ++;
    }
    return (e);
}

static void merge_lists(l_elem **head, size_t left_size, size_t right_size,
    int(*comp)(void *, void *))
{
    l_elem *left = *head;
    l_elem *right = elem_advance(left, left_size);

    while (left_size * right_size != 0){
        if (comp(left->content, right->content) <= 0){
            (*head) = left;
            head = &(*head)->next;
            left = left->next;
            left_size --;
        } else {
            (*head) = right;
            head = &(*head)->next;
            right = right->next;
            right_size --;
        }
    }
    if (left_size == 0)
        *head = right;
    if (right_size == 0)
        *head = left;
}

static void merge_sort(l_elem **first, size_t size, int(*comp)(void *, void *))
{
    size_t left_size = size / 2;
    size_t right_size = size - left_size;
    l_elem **center;
    l_elem *end = elem_advance(*first, size);

    (void)end;
    if (size == 1)
        return;
    merge_sort(first, left_size, comp);
    center = &elem_advance(*first, left_size - 1)->next;
    merge_sort(center, right_size, comp);
    merge_lists(first, left_size, right_size, comp);
    elem_advance(*first, size - 1)->next = end;
}

int list_sort(l_list *l, int(*comp)(void *, void *))
{
    if (l->len < 2)
        return (1);
    merge_sort(&l->first, l->len, comp);
    return (1);
}
