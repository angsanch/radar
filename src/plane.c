/*
** EPITECH PROJECT, 2024
** plane.c
** File description:
** Mange planes
*/

#include "../include/my.h"
#include "../include/radar.h"

static void update_display_elements(dn_sprite *plane, plane_inf *data)
{
    plane->display.draw_texture = data->on_air && data->texture_toggle;
    plane->display.draw_outline = data->on_air && data->outline_toggle;
}

void event_plane(dn_sprite *plane, dn_envinfo *env)
{
    plane_inf *data = plane->data;

    if (env->event->type == sfEvtKeyPressed){
        if (env->event->key.code == sfKeyS)
            data->texture_toggle = !data->texture_toggle;
        if (env->event->key.code == sfKeyL)
            data->outline_toggle = !data->outline_toggle;
        update_display_elements(plane, data);
    }
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
            update_display_elements(plane, data);
        }
    }
}
