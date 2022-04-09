/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** defeat_handle.c
*/

#include "tetris.h"

void defeat(game_t *game)
{
    int x;
    int y;
    int key;

    tetrim_to_area(game, &game->cur);
    while (1) {
        key = getch();
        if (key == game->key.quit)
            exit_ncurse(game, 0);
        if (key == 410)
            clear();
        size_handle(game);
        all_game(game);
    }
}
