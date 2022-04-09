/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** get_all_opt.c
*/

#include "tetris.h"

static void get_opt_value(game_t *game, char opt, char *opt_arg)
{
    switch (opt) {
        case 'l':
            game->key.left = my_getnbr(opt_arg); break;
        case 'r':
            game->key.right = my_getnbr(opt_arg); break;
        case 'd':
            game->key.drop = my_getnbr(opt_arg); break;
        case 't':
            game->key.turn = my_getnbr(opt_arg); break;
        case 'p':
            game->key.pause = my_getnbr(opt_arg); break;
        case 'L':
            game->info.lvl = my_getnbr(opt_arg); break;
        default: break;
    }
}

void get_all_opt(game_t *game, bool *debug_mode, int argc, char *argv[])
{
    int opt;

    while ((opt = getopt_long(\
    argc, argv, "L:l:r:t:d:q:p:wD", long_options, NULL)) != EOF) {
        game->next = opt == 'w' ? false : game->next;
        *debug_mode = opt == 'D' ? true : *debug_mode;
        get_opt_value(game, (char)opt, optarg);
    }
}
