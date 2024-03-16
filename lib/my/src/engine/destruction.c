/*
** EPITECH PROJECT, 2023
** destruction.c
** File description:
** Destroy the structs
*/

#include "../../include/my.h"

void destroy_texture(dn_texture *texture)
{
    sfTexture_destroy(texture->texture);
    free(texture->id);
    free(texture);
}

void destroy_sprite(dn_sprite *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfRectangleShape_destroy(sprite->display.outline);
    sfCircleShape_destroy(sprite->display.circle);
    sfText_destroy(sprite->display.text);
    sprite->destroy_data(sprite->data);
    free(sprite);
}

void destroy_scene(dn_scene *scene)
{
    list_destroy(scene->sprites);
    list_destroy(scene->textures);
    sfMusic_destroy(scene->music);
    free(scene->id);
    free(scene);
}

void destroy_window(dn_window *window)
{
    sfRenderWindow_close(window->window);
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->clock);
    list_destroy(window->scenes);
    free(window);
}
