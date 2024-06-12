/*
** EPITECH PROJECT, 2024
** radar.h
** File description:
** Planes
*/

#ifndef RADAR_H_
    #define RADAR_H_
    #include "engine.h"
    #include "my_printf.h"

typedef struct plane_inf_to_container {
    float x_vel;
    float y_vel;
    float duration;
    float delay;
    int on_air;
    int texture_toggle;
    int outline_toggle;
} plane_inf_t;

typedef struct tower_inf_to_container {
    int area_size;
} tower_inf_t;


int load_script(dn_window_t *window, char const *path);
void event_bg(dn_sprite_t *background, dn_envinfo_t *env);
void tick_bg(dn_sprite_t *background, dn_envinfo_t *env);
void event_tower(dn_sprite_t *tower, dn_envinfo_t *env);
void event_plane(dn_sprite_t *sprite, dn_envinfo_t *env);
void tick_plane(dn_sprite_t *plane, dn_envinfo_t *env);

#endif
