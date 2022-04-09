/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** area_handle.c
*/

#include "tetris.h"

void increase_level(game_t *game)
{
    game->info.lin++;
    if (game->info.lin % 10 == 0)
        game->info.lvl++;
}

char **remplace_area(char **area, int line)
{
    for (int i = line; i != 0; i--)
        for (int j = 0; area[i][j] != '\0'; j++)
            area[i][j] = area[i - 1][j];
    for (int i = 0; area[0][i] != '\0'; i++)
        area[0][i] = ' ';
    return area;
}

char **verif_complete_line(game_t *game, char **area)
{
    for (int i = 0; area[i] != NULL; i++) {
        if (my_str_isnum(area[i]) != 0) {
            area = remplace_area(area, i);
            increase_level(game);
        }
    }
    return area;
}

void tetrim_to_area(game_t *game, current_t *cur)
{
    for (int i = 0; cur->tetrim[i] != NULL; i++)
        for (int j = 0; cur->tetrim[i][j] != '\0'; j++)
            t_to_area_norme(game, cur, cur->tetrim[i][j], init_vect(i, j));
    init_current_info(cur, game->tetr, game);
    game->area = verif_complete_line(game, game->area);
}
