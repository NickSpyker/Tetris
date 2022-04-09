/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** current_possibility.c
*/

#include "tetris.h"

void can_rotate(game_t *game, current_t *cur)
{
    cur->rotate = true;
    if (cur->pos.x < 0)
        cur->rotate = false;
    if (cur->pos.x + cur->size > game->size.x)
        cur->rotate = false;
}

void can_go_down(game_t *game, current_t *cur)
{
    cur->down = true;
    if (cur->pos.y + cur->y_site.y == game->size.y - 1)
        cur->down = false;
    for (int i = 0; i < cur->size && cur->down; i++)
        for (int j = 0; j < cur->size && cur->down; j++)
            go_down_norme(game, cur, i, j);
}

void go_down_norme(game_t *game, current_t *cur, int i, int j)
{
    int y = cur->pos.y + j + 1;

    if (cur->tetrim[j][i] != ' ' && game->area[y][cur->pos.x + i] != ' ')
        cur->down = false;
}

bool can_move_left(game_t *gm, current_t *cur)
{
    int j = cur->x_site.x;
    int y = cur->pos.y;
    int x = cur->pos.x;

    for (int i = 0; i < cur->size; i++)
        if (cur->tetrim[i][j] != ' ' && gm->area[i + y][j + x - 1] != ' ')
            return false;
    return true;
}

bool can_move_rigth(game_t *gm, current_t *cur)
{
    int j = cur->x_site.y;
    int y = cur->pos.y;
    int x = cur->pos.x;

    for (int i = 0; i < cur->size; i++)
        if (cur->tetrim[i][j] != ' ' && gm->area[i + y][j + x + 1] != ' ')
            return false;
    return true;
}
