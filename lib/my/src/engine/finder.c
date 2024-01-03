/*
** EPITECH PROJECT, 2023
** finder.c
** File description:
** Find in list
*/

#include "../../include/my.h"

dn_texture *search_texture(dn_scene *scene, char *id)
{
    l_elem *e = scene->textures->first;

    while (e){
        if (my_strcmp(((dn_texture *)e->content)->id, id) == 0)
            return ((dn_texture *)e->content);
        e = e->next;
    }
    return (NULL);
}

dn_sprite *search_sprite(dn_scene *scene, size_t id)
{
    l_elem *e = scene->sprites->first;

    while (e){
        if (((dn_sprite *)e->content)->id == id)
            return ((dn_sprite *)e->content);
        e = e->next;
    }
    return (NULL);
}

int focus_scene(dn_window *window, char *id)
{
    l_elem *e = window->scenes->first;

    while (e){
        if (my_strcmp(((dn_scene *)e->content)->id, id) == 0){
            window->scene = e->content;
            return (1);
        }
        e = e->next;
    }
    return (0);
}
