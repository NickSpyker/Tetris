/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** key_handle.c
*/

#include "tetris.h"

void key_handle(game_t *game, int key, clock_t *start)
{
    if (game->pause) {
        if (key == game->key.pause)
            pause_game(game, start);
        if (key == game->key.quit)
            exit_ncurse(game, 0);
    } else {
        if (key == game->key.turn && game->cur.rotate)
            game->cur.tetrim = rotate(game->cur.tetrim);
        if (key == game->key.drop)
            drop(game, &game->cur);
        if (key == game->key.pause)
            pause_game(game, start);
        if (key == game->key.quit)
            exit_ncurse(game, 0);
        if (key == game->key.left)
            move_tetrim(game, &game->cur, left);
        if (key == game->key.right)
            move_tetrim(game, &game->cur, rigth);
    }
}

void pause_game(game_t *game, clock_t *start)
{
    if (game->pause) {
        game->pause = false;
        *start = clock();
    } else
        game->pause = true;
}
