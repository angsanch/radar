/*
** EPITECH PROJECT, 2024
** collisions.c
** File description:
** Collide objects
*/

#include "../../include/my.h"
#include "../../include/engine_utils.h"

static int present(void *sprite_void, void *nothing)
{
    (void)nothing;
    return (((dn_sprite *)sprite_void)->collision);
}

static void collide(dn_sprite *sprites, size_t amount)
{
    (void)sprite;
    (void)amount;
}

static sfIntRect sprite_to_rect(dn_sprite *sprite)
{
    return ((sfIntRect){sprite->position.x,
            sprite->position.y,
            sprite->display.outline_size.x,
            sprite->display.outline_size.y});
}

static void quarter(dn_sprite **sprites, size_t amount, sfIntRect *rect, int d)
{
    dn_sprite *quarters[4][amount];
    int lens[4] = {0, 0, 0, 0};
    int width = rect->width / 2;
    int height = rect->height / 2;
    sfIntRect rects[5] = {{rect->left, rect->top, width, height},
        {rect->left + width, rect->top, width, height},
        {rect->left, rect->top + height, width, height},
        {rect->left + width, rect->top + height, width, height}, {0, 0, 0, 0}};

    if (amount <= 5 || d >= 4)
        return;
    for (size_t i = 0; i < amount; i ++){
        rects[4] = sprite_to_rect(sprites[i]);
        for (size_t j = 0; j < 4; j ++){
            if (!sfIntRect_intersects(&rects[j], &rects[4], NULL))
                continue;
            quarters[j][lens[j]] = sprites[i];
            lens[j] ++;
        }
    }
    for (size_t i = 0; i < 4; i++)
        quarter(quarters[i], lens[i], &rects[i], d + 1);
    my_printf("%*s %d %d %d %d\n", d, "", lens[0], lens[1], lens[2], lens[3]);
}

void collisions(dn_window *window)
{
    size_t active_objects;
    dn_sprite **list;
    size_t i = 0;
    sfIntRect rect = {0, 0, window->resolution.x, window->resolution.y};

    if (window->manage_collision == NULL)
        return;
    active_objects = list_total_fulfil(window->scene->sprites, &present, NULL);
    if (active_objects == 0)
        return;
    list = malloc(sizeof(dn_sprite *) * active_objects);
    if (list == NULL)
        return;
    for (l_elem *e = window->scene->sprites->first; e != NULL; e = e->next){
        if (present(e->content, NULL)){
            list[i] = e->content;
            i ++;
        }
    }
    quarter(list, i, &rect, 0);
    my_printf("-----------------------\n");
}

void window_collisions(dn_window *window, void (*manage)(void *, void *))
{
    window->manage_collision = manage;
}
