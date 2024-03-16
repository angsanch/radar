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

static sfIntRect sprite_to_rect(dn_sprite *sprite)
{
    return ((sfIntRect){sprite->position.x,
            sprite->position.y,
            sprite->display.outline_size.x,
            sprite->display.outline_size.y});
}

static void check_collision(dn_sprite **sprites, l_list *colls,
    sfIntRect *rects, sfVector2i *indexes)
{
    dn_coll_sprites *col = NULL;

    if (sfIntRect_intersects(&rects[0], &rects[1], NULL)){
        col = malloc(sizeof(dn_coll_sprites) * 1);
        if (col == NULL)
            return;
        *col = (dn_coll_sprites){sprites[indexes->x]->id,
            sprites[indexes->y]->id};
        list_push(colls, col);
        col = NULL;
    }
}

static void collide(dn_sprite **sprites, size_t amount, l_list *colls)
{
    sfIntRect rects[2];
    sfVector2i sprites_index;

    (void)sprites;
    if (amount <= 1)
        return;
    for (size_t i = 0; i < amount - 1; i++){
        rects[0] = sprite_to_rect(sprites[i]);
        for (size_t j = i + 1; j < amount; j++){
            rects[1] = sprite_to_rect(sprites[j]);
            sprites_index = (sfVector2i){i, j};
            check_collision(sprites, colls, rects, &sprites_index);
        }
    }
}

static void separate_quarters(quarter_info *info, sfIntRect(*rects)[5],
    dn_sprite *(*quarters)[4][info->amount], int (*lens)[4])
{
    int collision;

    for (size_t i = 0; i < info->amount; i ++){
        (*rects)[4] = sprite_to_rect(info->sprites[i]);
        for (size_t j = 0; j < 4; j ++){
            collision = sfIntRect_intersects(&(*rects)[j], &(*rects)[4], NULL);
            (*quarters)[j][(*lens)[j]] = (dn_sprite *)
                ((size_t)info->sprites[i] * collision);
            (*lens)[j] += collision;
        }
    }
}

static void quarter(quarter_info *info, int d, l_list *colls)
{
    quarter_info next_inf;
    dn_sprite *quarters[4][info->amount];
    int lens[4] = {0, 0, 0, 0};
    int width = info->rect->width / 2;
    int height = info->rect->height / 2;
    sfIntRect *rect = info->rect;
    sfIntRect rects[5] = {{rect->left, rect->top, width, height},
        {rect->left + width, rect->top, width, height},
        {rect->left, rect->top + height, width, height},
        {rect->left + width, rect->top + height, width, height}, {0, 0, 0, 0}};

    if (info->amount <= 5 || d >= 4){
        collide(info->sprites, info->amount, colls);
        return;
    }
    separate_quarters(info, &rects, &quarters, &lens);
    for (size_t i = 0; i < 4; i++){
        next_inf = (quarter_info){quarters[i], lens[i], &rects[i]};
        quarter(&next_inf, d + 1, colls);
    }
}

void add_active(quarter_info *info, dn_window *window)
{
    for (l_elem *e = window->scene->sprites->first; e != NULL; e = e->next){
        if (present(e->content, NULL)){
            info->sprites[info->amount] = e->content;
            info->amount ++;
        }
    }
}

void collisions(dn_window *window)
{
    size_t active_objects;
    sfIntRect rect = {0, 0, window->resolution.x, window->resolution.y};
    quarter_info info = {NULL, 0, &rect};
    l_list *colls = list_create(&free);

    if (colls == NULL)
        return;
    if (window->manage_collision == NULL)
        return;
    active_objects = list_count_fulfil(window->scene->sprites, &present, NULL);
    if (active_objects == 0)
        return;
    info.sprites = malloc(sizeof(dn_sprite *) * active_objects);
    if (info.sprites == NULL)
        return;
    add_active(&info, window);
    quarter(&info, 0, colls);
    list_iter(colls, (void *)window->manage_collision, window);
    list_destroy(colls);
    free(info.sprites);
}

void window_collisions(dn_window *window,
    void (*manage)(dn_coll_sprites *, dn_window *))
{
    window->manage_collision = manage;
}
