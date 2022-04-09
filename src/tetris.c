/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** tetris.c
*/

#include "tetris.h"

void tetris(game_t *game)
{
    clock_t begin;
    clock_t start;

    init_ncurse();
    display_menu(game, &begin, &start);
    while (!game->end) {
        clock_handle(begin, &start, game);
        while (game->pause) {
            all_game(game);
            usleep(1);
            key_handle(game, getch(), &start);
        }
        size_handle(game);
        tetris_norme(game);
        all_game(game);
        key_handle(game, getch(), &start);
    }
    defeat(game);
    exit_ncurse(game, 0);
}

void tetris_norme(game_t *game)
{
    can_go_down(game, &game->cur);
    can_rotate(game, &game->cur);
    get_current_site(&game->cur);
    if (!game->cur.down)
        tetrim_to_area(game, &game->cur);
}

void clock_handle(clock_t begin, clock_t *start, game_t *game)
{
    clock_t current = clock();
    int timer = (current - *start) * 10 / CLOCKS_PER_SEC;

    game->info.tim = (current - begin) / CLOCKS_PER_SEC;
    if (timer != 0 && timer == 15 - game->info.lvl) {
        tetrim_go_down(game, &game->cur);
        *start = clock();
    }
}
