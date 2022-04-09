/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** display_tetris.c
*/

#include "tetris.h"

void display_color(char star, vect_t pos)
{
    if (star != ' ') {
        attron(COLOR_PAIR(star - 48));
        mvprintw(pos.y, pos.x, "*");
        attroff(COLOR_PAIR(star - 48));
    }
}

void display_tetris(game_t *game)
{
    int x = (COLS - game->window.x) / 2;
    int y = (LINES - game->window.y) / 2;
    vect_t pos;

    for (int i = 0; game->area[i] != NULL; i++)
        for (int j = 0; game->area[i][j] != '\0'; j++) {
            pos = init_vect(29 + x + j, 1 + y + i);
            display_color(game->area[i][j], pos);
        }
}

void display_array(char **tetrim, vect_t pos)
{
    for (int i = 0; tetrim[i] != NULL; i++)
        for (int j = 0; tetrim[i][j] != '\0'; j++)
            display_color(tetrim[i][j], init_vect(pos.x + j, pos.y + i));
}

void display_next(game_t *game, vect_t pos, tetriminos_t *tetrim)
{
    attron(COLOR_PAIR(COLOR_WHITE));
    if (game->next == false)
        mvprintw(pos.y + 2, pos.x + 4, "?");
    else
        display_array(tetrim[game->cur.cur_next.y].form, pos);
}
