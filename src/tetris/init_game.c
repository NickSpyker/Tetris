/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** init_game.c
*/

#include "tetris.h"

void init_game(game_t *gm)
{
    int rand1;

    gm->end = false;
    gm->info.lin = 0;
    gm->info.sco = 0;
    gm->pause = false;
    gm->window = init_vect(43 + gm->size.x, 18);
    if (gm->size.y + 2 > 18)
        gm->window.y = gm->size.y + 2;
    gm->area = my_array_alloc(gm->size.x, gm->size.y);
    srand((intptr_t)gm->area);
    for (int i = 0; i < gm->size.y; i++)
        for (int j = 0; j < gm->size.x; j++)
            gm->area[i][j] = ' ';
    while (!gm->tetr[rand1 = rand() % gm->nb_tetrim].valid);
    gm->cur.cur_next = init_vect(-1, rand1);
    gm->cur.x_site = init_vect(0, 0);
    gm->cur.y_site = init_vect(0, 0);
    init_current_info(&gm->cur, gm->tetr, gm);
}
