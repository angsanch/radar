/*
** EPITECH PROJECT, 2024
** script_loader.c
** File description:
** Load script
*/

#include "../include/radar.h"
#include <math.h>

static int check_line_format(char const *line, int params)
{
    int i = 0;

    if (line[1] != ' ' || !my_isalpha(line[0]) || !my_isnumeric(line[2]))
        return (0);
    line += 2;
    while (i < params){
        while (my_isnumeric(*line))
            line ++;
        if (*line != ' ' && i != params - 1)
            return (0);
        line ++;
        i ++;
    }
    return (*line == 0 || *line == '\n');
}

static unsigned int get_next_number(char const **line)
{
    unsigned int result = my_getnbr(*line);

    *line += my_intlen(result) + 1;
    return (result);
}

static void make_path(dn_sprite_t *plane, plane_inf_t *data, unsigned int speed)
{
    float distance = sqrt(pow(data->x_vel, 2) + pow(data->y_vel, 2));

    data->duration = distance / speed * 1000;
    plane->angle = atan(data->y_vel / data->x_vel) * 180 / M_PI + 90;
    if (data->x_vel < 0)
        plane->angle += 180;
    data->x_vel /= data->duration;
    data->y_vel /= data->duration;
}

static int parse_plane(dn_sprite_t *plane, plane_inf_t *data, char const *line)
{
    if (!check_line_format(line, 6))
        return (0);
    line += 2;
    plane->position.x = get_next_number(&line);
    plane->position.y = get_next_number(&line);
    data->x_vel = get_next_number(&line) - plane->position.x;
    data->y_vel = get_next_number(&line) - plane->position.y;
    make_path(plane, data, get_next_number(&line));
    data->delay = get_next_number(&line) * 1000;
    data->texture_toggle = true;
    data->outline_toggle = true;
    return (1);
}

static void set_plane_graphics(dn_sprite_t *plane)
{
    plane->display.draw_texture = false;
    plane->display.rotate_outline = false;
}

static int make_plane(dn_window_t *window, char const *line)
{
    plane_inf_t *data = malloc(sizeof(plane_inf_t) * 1);

    if (data == NULL)
        return (-1);
    data->on_air = false;
    add_sprite(window->scene, 0, 0);
    add_sprite_set_data(window->scene, data, &free);
    if (!parse_plane(window->scene->creation, data, line))
        return (-1);
    add_sprite_set_functions(window->scene, &tick_plane, &event_plane);
    add_sprite_set_graphics(window->scene, "plane", &set_plane_graphics);
    add_push_sprite(window->scene);
    return (1);
}

static void set_tower_graphics(dn_sprite_t *tower)
{
    tower_inf_t *data = tower->data;

    tower->display.draw_circle = true;
    tower->display.circle_size = data->area_size;
}

static int make_tower(dn_window_t *window, char const *ln)
{
    tower_inf_t *data = malloc(sizeof(tower_inf_t) * 1);

    if (data == NULL)
        return (-1);
    add_sprite(window->scene, 0, 0);
    add_sprite_set_data(window->scene, data, &free);
    if (!check_line_format(ln, 3))
        return (-1);
    ln += 2;
    ((dn_sprite_t *)window->scene->creation)->position.x = get_next_number(&ln);
    ((dn_sprite_t *)window->scene->creation)->position.y = get_next_number(&ln);
    data->area_size = get_next_number(&ln);
    add_sprite_set_graphics(window->scene, "tower", &set_tower_graphics);
    add_sprite_set_functions(window->scene, NULL, &event_tower);
    add_push_sprite(window->scene);
    return (1);
}

static int process_line(dn_window_t *window, char const *line, unsigned int lns)
{
    int status;

    if (line == NULL)
        return (0);
    if (line[0] == 'A')
        status = make_plane(window, line);
    else if (line[0] == 'T')
        status = make_tower(window, line);
    if (status < 0)
        my_dprintf(2, "Error while processing line (%u)\n", lns);
    return (status);
}

int load_script(dn_window_t *window, char const *path)
{
    int fd = open(path, O_RDONLY);
    unsigned int lines = 0;
    char *line;

    if (fd < 0){
        my_dprintf(2, "Unable to open file\n");
        return (84);
    }
    do {
        lines ++;
        line = get_next_line(fd);
        if (process_line(window, line, lines) < 0)
            return (84);
        free(line);
    } while (line != NULL);
    if (lines == 1){
        my_dprintf(2, "No information to be read from file\n");
        return (84);
    }
    return (0);
}
