/*
** EPITECH PROJECT, 2024
** tower.c
** File description:
** Control towers
*/

#include "../include/my.h"

void event_tower(dn_sprite *tower, dn_envinfo *env)
{
    if (env->event->type == sfEvtKeyPressed){
        if (env->event->key.code == sfKeyS)
            tower->display.draw_texture = !tower->display.draw_texture;
        if (env->event->key.code == sfKeyL)
            tower->display.draw_outline = !tower->display.draw_outline;
    }
}