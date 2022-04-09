/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** menu_handling.c
*/

#include "tetris.h"

void display_menu(game_t *game, clock_t *begin, clock_t *start)
{
    char msg[] = "Press space to play";
    vect_t pos;

    while (1) {
        pos = init_vect(COLS / 2 - 13, LINES / 2 - 10);
        size_handle(game);
        display_tetris_logo(pos);
        mvprintw(LINES / 2, COLS / 2 - (my_strlen(msg) / 2), "%s", msg);
        refresh();
        if (menu_key(game, getch(), begin, start) == 1)
            return;
    }
}

int menu_key(game_t *game, int key, clock_t *begin, clock_t *start)
{
    if (key == 32) {
        *begin = clock();
        *start = clock();
        all_game(game);
        refresh();
        return 1;
    }
    if (key == 410)
        clear();
    if (key == game->key.quit)
        exit_ncurse(game, 0);
    return 0;
}
