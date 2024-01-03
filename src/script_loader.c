/*
** EPITECH PROJECT, 2024
** script_loader.c
** File description:
** Load script
*/

#include "../include/my.h"

static int make_plane(dn_window *window, char const *line)
{
    (void)line;
    add_sprite(window->scene);
    add_sprite_set_graphics(window->scene, "plane", NULL);
    add_push_sprite(window->scene);
    return (1);
}

static int make_tower(dn_window *window, char const *line)
{
    (void)line;
    add_sprite(window->scene);
    add_sprite_set_graphics(window->scene, "tower", NULL);
    add_push_sprite(window->scene);
    return (1);
}

static int process_line(dn_window *window, char const *line, unsigned int lns)
{
    int status;

    if (line == NULL)
        return (0);
    if (line[0] == 'A')
        status = make_plane(window, line);
    else if (line[0] == 'T')
        status = make_tower(window, line);
    if (status < 0)
        my_dprintf(2, "Invalid line (%u)\n", lns + 1);
    return (status);
}

int load_script(dn_window *window, char const *path)
{
    int fd = open(path, O_RDONLY);
    unsigned int lines = 0;
    char *line;

    if (fd < 0){
        my_dprintf(2, "Unable to open file\n");
        return (84);
    }
    do {
        line = get_next_line(fd);
        if (process_line(window, line, lines) < 0)
            return (84);
        free(line);
        lines ++;
    } while (line != NULL);
    if (lines == 0){
        my_dprintf(2, "No information to be read from file\n");
        return (84);
    }
    return (0);
}
