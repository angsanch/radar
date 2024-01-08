/*
** EPITECH PROJECT, 2024
** my_radar.c
** File description:
** Control arplanes crashing
*/

#include "../include/my.h"
#include "../include/radar.h"

static void manage_crash(dn_coll_sprites *sprites, dn_window *window)
{
    delete_sprite_by_id(window->scene, sprites->id1);
    delete_sprite_by_id(window->scene, sprites->id2);
}

int game(char const *script_path)
{
    int status;
    dn_window *window = create_window(1920, 1080, "Aircaft accident overview",
        sfClose | sfResize);

    limit_fps(window, 30);
    create_texture(window->scene, "assets/map.png", 1, 1);
    create_texture(window->scene, "assets/plane.png", 1, 1);
    create_texture(window->scene, "assets/tower.png", 1, 1);
    add_sprite(window->scene);
    add_sprite_set_graphics(window->scene, "map", NULL);
    add_sprite_set_functions(window->scene, &tick_bg, &event_bg);
    add_push_sprite(window->scene);
    window_collisions(window, &manage_crash);
    status = load_script(window, script_path);
    if (status == 0)
        while (tick_window(window));
    else
        my_dprintf(2, "Problem loading script\n");
    destroy_window(window);
    return (status);
}

void print_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t\'L\' key enable/disable hitboxes and areas.\n");
    my_putstr("\t\'S\' key enable/disable sprites.\n");
    my_putstr("\t\'Q\' key to quit.\n");
}

int main(int argc, char **argv)
{
    if (argc == 2){
        if (my_strcmp(argv[1], "-h") == 0)
            print_help();
        else
            return (game(argv[1]));
    } else {
        my_dprintf(2, "Incorrect amount of parameters.\n" \
            "%d given but 2 required\n", argc);
        return (84);
    }
    return (0);
}
