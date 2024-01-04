/*
** EPITECH PROJECT, 2024
** radar.h
** File description:
** Planes
*/

#ifndef RADAR_H_
    #define RADAR_H_

typedef struct plane_info_container {
    float x_vel;
    float y_vel;
    float duration;
    float delay;
    int on_air;
    int texture_toggle;
    int outline_toggle;
} plane_inf;

typedef struct tower_info_container {
    int area_size;
} tower_inf;


int load_script(dn_window *window, char const *path);
void tick_background(dn_sprite *background, dn_envinfo *env);
void event_plane(dn_sprite *sprite, dn_envinfo *env);
void tick_plane(dn_sprite *plane, dn_envinfo *env);

#endif
