/*
** EPITECH PROJECT, 2023
** controller.c
** File description:
** Control the amount of fps
*/

#include "../../include/my.h"

void limit_fps(dn_window *window, unsigned int limit)
{
    sfRenderWindow_setFramerateLimit(window->window, limit);
}
