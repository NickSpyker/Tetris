/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** mv_start_to_nbr.c
*/

#include "tetris.h"

static void change_to_nbr(tetriminos_t *tetri)
{
    while (7 < tetri->color--);
    tetri->color = tetri->color == 0 ? 7 : tetri->color;
    for (int x = 0; x < tetri->size; x++)
        for (int y = 0; y < tetri->size; y++)
            tetri->form[x][y] = tetri->form[x][y] == '*' ? \
            tetri->color + '0' : ' ';
}

void mv_start_to_nbr(game_t *game)
{
    for (int i = 0; i < game->nb_tetrim; i++)
        change_to_nbr(&game->tetr[i]);
}
