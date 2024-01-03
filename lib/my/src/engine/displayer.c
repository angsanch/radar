/*
** EPITECH PROJECT, 2024
** displayer.c
** File description:
** Put sprites on screen
*/

#include "../../include/my.h"

static void display_sprite_texture(dn_sprite *sprite, sfRenderWindow *window)
{
    if (sprite->display.texture == NULL || !sprite->display.draw_texture)
        return;
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setTexture(sprite->sprite, sprite->display.texture->texture,
        sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->display.rect);
    sfSprite_setRotation(sprite->sprite,
        sprite->angle * sprite->display.rotate_texture);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

static void display_sprite_outline(dn_sprite *sprite, sfRenderWindow *window)
{
    if (sprite->display.outline == NULL || !sprite->display.draw_outline)
        return;
    sfRectangleShape_setSize(sprite->display.outline,
        (sfVector2f){sprite->display.rect.width, sprite->display.rect.height});
    sfRectangleShape_setPosition(sprite->display.outline, sprite->position);
    sfRectangleShape_setOutlineThickness(sprite->display.outline, 1);
    sfRectangleShape_setOutlineColor(sprite->display.outline,
        sprite->display.outline_color);
    sfRectangleShape_setRotation(sprite->display.outline,
        sprite->angle * sprite->display.rotate_outline);
    sfRenderWindow_drawRectangleShape(window, sprite->display.outline, NULL);
}

void display_sprite(void *sprite_void, void *window_void)
{
    dn_sprite *sprite = sprite_void;
    sfRenderWindow *window = window_void;

    display_sprite_texture(sprite, window);
    display_sprite_outline(sprite, window);
}
