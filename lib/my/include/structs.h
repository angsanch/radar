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

typedef struct file_buffer_container {
    char *buffer;
    size_t buff_len;
    char *line;
    ssize_t len;
} file_buffer;

typedef struct linked_list_element {
    void *content;
    struct linked_list_element *next;
} l_elem;
typedef struct linked_list_container {
    size_t len;
    l_elem *first;
    void(*del)(void *);
} l_list;


typedef struct dn_collision_sprites dn_coll_sprites;

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
    void(*manage_collision)(dn_coll_sprites *, struct dn_window_container *);
    bool to_be_closed;
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
    sfVector2f outline_size;
    bool draw_outline;
    sfCircleShape *circle;
    sfColor circle_color;
    float circle_size;
    bool draw_circle;
} dn_display_info;
typedef struct dn_sprite_container {
    size_t id;
    sfSprite *sprite;
    float angle;
    sfVector2f position;
    sfVector2f offset;
    sfVector2f center;
    dn_display_info display;
    void(*tick)(struct dn_sprite_container *, dn_envinfo *);
    void(*event)(struct dn_sprite_container *, dn_envinfo *);
    void(*destroy_data)(void *);
    bool collision;
    void *data;
} dn_sprite;
struct dn_collision_sprites {
    size_t id1;
    size_t id2;
};

#endif
