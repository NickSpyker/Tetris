/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** tetris_norme.c
*/

#include "tetris.h"

void t_to_area_norme(game_t *game, current_t *cur, char current, vect_t vect)
{
    if (current != ' ') {
        game->area[vect.x + cur->pos.y][vect.y + cur->pos.x] = current;
        game->info.sco++;
    }
}
