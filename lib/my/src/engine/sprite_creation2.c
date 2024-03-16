/*
** EPITECH PROJECT, 2023
** sprite_creation.c
** File description:
** Smart sprite creation
*/

#include "../../include/my.h"

void add_sprite_set_text(dn_scene *scene, char *text, sfColor color,
    size_t size)
{
    dn_sprite *sprite = scene->creation;

    sfText_setString(sprite->display.text, text);
    sprite->display.text_color = color;
    if (size != 0)
        sprite->display.text_size = size;
}
