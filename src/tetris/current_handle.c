/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** current_handle.c
*/

#include "tetris.h"

char **get_current_form(tetriminos_t tetrim)
{
    char **cur = my_array_alloc(tetrim.nbr_cols + 1, tetrim.nbr_rows + 1);

    for (int i = 0; tetrim.form[i] != NULL; i++)
        cur[i] = my_strdup(tetrim.form[i]);
    cur[my_arraylen(tetrim.form)] = NULL;
    return cur;
}

void init_current_info(current_t *cur, tetriminos_t *tetrim, game_t *gm)
{
    int random;

    while (!tetrim[random = rand() % gm->nb_tetrim].valid);
    cur->cur_next = init_vect(cur->cur_next.y, random);
    cur->tetrim = get_current_form(tetrim[cur->cur_next.x]);
    cur->size = my_arraylen(cur->tetrim);
    cur->pos = init_vect(gm->size.x / 2 - cur->size / 2, 0);
    get_current_site(cur);
    can_go_down(gm, cur);
    if (!cur->down)
        gm->end = true;
}

void get_cur_x_site(current_t *cur, int i, int j)
{
    if (cur->tetrim[i][j] != ' ') {
        if (j < cur->x_site.x)
            cur->x_site.x = j;
        else if (j > cur->x_site.y)
            cur->x_site.y = j;
    }
}

void get_cur_y_site(current_t *cur, int i, int j)
{
    if (cur->tetrim[i][j] != ' ') {
        if (i < cur->y_site.x)
            cur->y_site.x = i;
        else if (i > cur->y_site.y)
            cur->y_site.y = i;
    }
}

void get_current_site(current_t *cur)
{
    cur->x_site = init_vect(cur->size, 0);
    cur->y_site = init_vect(cur->size, 0);
    for (int i = 0; cur->tetrim[i] != NULL; i++)
        for (int j = 0; cur->tetrim[i][j] != '\0'; j++) {
            get_cur_x_site(cur, i, j);
            get_cur_y_site(cur, i, j);
        }
}
