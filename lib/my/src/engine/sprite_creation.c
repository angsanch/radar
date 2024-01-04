/*
** EPITECH PROJECT, 2023
** sprite_creation.c
** File description:
** Smart sprite creation
*/

#include "../../include/my.h"

void add_sprite(dn_scene *scene)
{
    scene->creation = create_sprite(scene);
}

void add_sprite_set_graphics(dn_scene *scene, char *texture_id,
    void(*config)(dn_sprite *))
{
    dn_texture *texture = search_texture(scene, texture_id);

    sprite_link_texture(scene->creation, texture);
    if (config != NULL)
        config(scene->creation);
}

void add_sprite_set_functions(dn_scene *scene,
    void(*tick)(struct dn_sprite_container *, dn_envinfo *),
    void(*event)(struct dn_sprite_container *, dn_envinfo *))
{
    dn_sprite *sprite = scene->creation;

    sprite->tick = tick;
    sprite->event = event;
}

void add_push_sprite(dn_scene *scene)
{
    scene->creation = NULL;
}

void add_sprite_set_data(dn_scene *scene, void *data,
    void(*destroy_data)(void *))
{
    sprite_add_data(scene->creation, data, destroy_data);
}
