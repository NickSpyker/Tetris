/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** move_tetrim.c
*/

#include "tetris.h"

char **rotate(char **tetrim)
{
    int x = my_strlen(tetrim[0]);
    int y = my_arraylen(tetrim);
    char **rotate = my_array_alloc(x, y);

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            rotate[i][j] = tetrim[y - 1 - j][i];
    return rotate;
}

void move_tetrim(game_t *gm, current_t *cur, int direct)
{
    if (direct == left && cur->x_site.x + cur->pos.x == 0)
        return;
    if (direct == rigth && cur->pos.x + cur->x_site.y == gm->size.x - 1)
        return;
    if (direct == left && !can_move_left(gm, cur))
        return;
    if (direct == rigth && !can_move_rigth(gm, cur))
        return;
    cur->pos.x += direct;
    return;
}

void tetrim_go_down(game_t *game, current_t *cur)
{
    (void)game;
    if (!cur->down)
        return;
    cur->pos.y++;
}

void drop(game_t *game, current_t *cur)
{
    while (cur->down) {
        tetrim_go_down(game, cur);
        can_go_down(game, cur);
    }
}
