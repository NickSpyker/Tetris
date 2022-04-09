/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** debug_mode.c
*/

#include "tetris.h"

static void print_info_key(game_t *game)
{
    write_this_x_two("Key left: ", game->key.left == KEY_LEFT ? \
    "KEY_LEFT" : debug_sd(game->key.left));
    write_this(" (?)", (int)game->key.left);
    write_this_x_two("\nKey right: ", game->key.right == KEY_RIGHT ? \
    "KEY_RIGHT" : debug_sd(game->key.right));
    write_this(" (?)", (int)game->key.right);
    write_this_x_two("\nKey turn: ", game->key.turn == KEY_UP ? \
    "KEY_UP" : debug_sd(game->key.turn));
    write_this(" (?)", (int)game->key.turn);
    write_this_x_two("\nKey drop: ", game->key.drop == KEY_DOWN ? \
    "KEY_DOWN" : debug_sd(game->key.drop));
    write_this(" (?)", (int)game->key.drop);
    write_this_x_two("\nKey quit: ", debug_sd(game->key.quit));
    write_this(" (?)", (int)game->key.quit);
    write_this_x_two("\nKey pause: ", debug_sd(game->key.pause));
    write_this(" (?)", (int)game->key.pause);
}

static void print_info(game_t *game)
{
    print_info_key(game);
    write_this_x_two("\nNext: ", game->next ? "Yes\n" : "No\n");
    write_this("Level: ?\n", game->info.lvl);
    write_this("Size: ?*", game->size.y);
    write_this("?\n", game->size.x);
}

static void display_debug_mode(game_t *game)
{
    print_info(game);
    write_this("\nNumber of tetriminos: ?\n", game->nb_tetrim);
    for (int i = 0; i < game->nb_tetrim; i++) {
        write_this("Tetriminos '", 0);
        game->tetr[i].name = get_name(game->path_to_all_tetriminos[i]);
        write_this(game->tetr[i].name, 0);
        if (!game->tetr[i].valid) {
            write_this("': error\n", 0);
            continue;
        }
        write_this("': size ?*", game->tetr[i].nbr_cols);
        write_this("?, color ", game->tetr[i].nbr_rows);
        write_this("?\n", game->tetr[i].color);
        print_tetriminos(game->tetr[i].valid, game->tetr[i].form, \
        game->tetr[i].nbr_rows, game->tetr[i].nbr_cols);
    }
}

static void init_all(game_t *game)
{
    game->next = true;
    game->info.lvl = 1;
    game->size = (vect_t){10, 20};
    game->key.right = KEY_RIGHT;
    game->key.left = KEY_LEFT;
    game->key.turn = KEY_UP;
    game->key.drop = KEY_DOWN;
    game->key.quit = 113;
    game->key.pause = 32;
}

void debug_mode(int argc, char *argv[], game_t *game)
{
    bool debug_mode = false;
    char optstring[] = "-LlrtdqpwD";
    bool print_help = false;

    init_all(game);
    for (int i = 0; game->path_to_all_tetriminos[i]; i++)
        game->tetr[i] = *tetri_pars(my_strcat("tetriminos/", \
        game->path_to_all_tetriminos[i]));
    get_all_opt(game, &debug_mode, argc, argv);
    for (int i = 1; i < argc; i++)
        if (!my_strcmp(argv[i], "--help"))
            print_help = true;
    if (debug_mode) {
        display_debug_mode(game);
        if (print_help)
            print_help_if_needed(argc, argv, true);
        exit(0);
    }
}
