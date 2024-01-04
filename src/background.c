/*
** EPITECH PROJECT, 2024
** background.c
** File description:
** Background script
*/

#include "../include/my.h"
#include "../include/radar.h"

static int is_plane(void *sprite_void, void *nothing)
{
    dn_sprite *plane = sprite_void;

    (void)nothing;
    return (my_strcmp(plane->display.texture->id, "plane") == 0);
}

void tick_background(dn_sprite *background, dn_envinfo *env)
{
    (void)background;
    if (list_total_fulfil(env->window->scene->sprites, &is_plane, NULL) == 0)
        env->window->to_be_closed = true;
}
