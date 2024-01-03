/*
** EPITECH PROJECT, 2023
** structs.h
** File description:
** Structs for libmy
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct linked_list_element {
    void *content;
    struct linked_list_element *next;
} l_elem;
typedef struct linked_list_container {
    size_t len;
    l_elem *first;
    void(*del)(void *);
} l_list;

typedef struct dn_texture_container {
    char *id;
    sfTexture *texture;
    size_t x_tiles;
    size_t y_tiles;
} dn_texture;
typedef struct dn_scene_container {
    l_list *sprites;
    l_list *textures;
    sfMusic *music;
    size_t id_sprite;
    char *id;
    void *creation;
} dn_scene;
typedef struct dn_window_container {
    sfRenderWindow *window;
    sfClock *clock;
    dn_scene *scene;
    l_list *scenes;
    sfVector2i resolution;
    sfVector2i size;
} dn_window;
typedef struct dn_environment_info {
    float time_delta;
    dn_window *window;
    sfEvent *event;
}dn_envinfo;
typedef struct dn_sprite_display_info {
    int rotate_texture;
    int rotate_outline;
    dn_texture *texture;
    sfIntRect rect;
    bool draw_texture;
    sfRectangleShape *outline;
    sfColor outline_color;
    bool draw_outline;
} dn_display_info;
typedef struct dn_sprite_container {
    size_t id;
    sfSprite *sprite;
    float angle;
    sfVector2f position;
    dn_display_info display;
    void(*tick)(struct dn_sprite_container *, dn_envinfo *);
    void(*event)(struct dn_sprite_container *, dn_envinfo *);
    void(*destroy_data)(void *);
    void *data;
} dn_sprite;

#endif
