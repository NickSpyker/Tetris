/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** init_ncurse.c
*/

#include "tetris.h"

void init_ncurse(void)
{
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);
    start_color();
    for (int i = 1; i < 8; i++)
        init_pair(i, i, COLOR_BLACK);
}

void exit_ncurse(game_t *game, int end)
{
    set_high_score(game, game->info.sco);
    endwin();
    exit(end);
}

void size_handle(game_t *game)
{
    char msg[] = "enlarge the terminal to play";

    while (LINES < game->window.y || COLS < game->window.x) {
        mvprintw(LINES / 2, COLS / 2 - (my_strlen(msg) / 2), msg);
        refresh();
        if (getch() == 410)
            clear();
        if (LINES > game->window.y && COLS > game->window.x)
            clear();
    }
}
