/*
** EPITECH PROJECT, 2024
** tower.c
** File description:
** Control towers
*/

#include "../include/radar.h"

void event_tower(dn_sprite_t *tower, dn_envinfo_t *env)
{
    if (env->event->type == sfEvtKeyPressed){
        if (env->event->key.code == sfKeyS)
            tower->display.draw_texture = !tower->display.draw_texture;
        if (env->event->key.code == sfKeyL)
            tower->display.draw_circle = !tower->display.draw_circle;
    }
}
