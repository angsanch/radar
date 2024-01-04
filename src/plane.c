/*
** EPITECH PROJECT, 2024
** plane.c
** File description:
** Mange planes
*/

#include "../include/my.h"
#include "../include/radar.h"

void event_plane(dn_sprite *sprite, dn_envinfo *env)
{
    (void)sprite;
    (void)env;
}

void tick_plane(dn_sprite *plane, dn_envinfo *env)
{
    plane_inf *data = plane->data;

    if (data->on_air){
        plane->position.x += data->x_vel * env->time_delta;
        plane->position.y += data->y_vel * env->time_delta;
        data->duration -= env->time_delta;
        if (data->duration < 0){
            delete_sprite_by_id(env->window->scene, plane->id);
        }
    } else {
        data->delay -= env->time_delta;
        if (data->delay < 0){
            data->on_air = true;
            plane->display.draw_texture = true;
            plane->display.draw_outline = true;
        }
    }
}
