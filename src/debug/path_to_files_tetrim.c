/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** fill_path_to_files_tetriminos.c
*/

#include "tetris.h"
#include "my.h"

static int get_nbr_of_files(void)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dirp;
    int result = 0;

    if (dir == NULL)
        my_putstr_err(\
        "ERROR: failed to read tetriminos folder (count function) !\n");
    while ((dirp = readdir(dir)) != NULL) {
        if (!my_strcmp(dirp->d_name, ".") || !my_strcmp(dirp->d_name, ".."))
            continue;
        result++;
    }
    closedir(dir);
    return result;
}

static void str_swap(char **str_a, char **str_b)
{
    char *temp;

    temp = *str_a;
    *str_a = *str_b;
    *str_b = temp;
}

static void sort_tetriminos(game_t *game)
{
    bool re_loop = false;

    for (int i = 0; i < game->nb_tetrim - 1; i++) {
        if (game->path_to_all_tetriminos[i][0] < \
        game->path_to_all_tetriminos[i + 1][0])
            continue;
        str_swap(&game->path_to_all_tetriminos[i], \
        &game->path_to_all_tetriminos[i + 1]);
        i = 0;
        re_loop = true;
    }
    if (re_loop)
        sort_tetriminos(game);
}

void fill_path_to_files_tetriminos(game_t *game)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dirp;
    int nbr_files;
    int i = 0;

    if (dir == NULL)
        my_putstr_err("ERROR: failed to read tetriminos folder !\n");
    nbr_files = get_nbr_of_files();
    game->path_to_all_tetriminos = malloc(sizeof(char *) * (nbr_files + 1));
    game->path_to_all_tetriminos[nbr_files] = NULL;
    while ((dirp = readdir(dir)) != NULL) {
        if (!my_strcmp(dirp->d_name, ".") || !my_strcmp(dirp->d_name, ".."))
            continue;
        game->path_to_all_tetriminos[i++] = my_malloc_strcpy(dirp->d_name);
    }
    closedir(dir);
    game->nb_tetrim = nbr_files;
    sort_tetriminos(game);
    game->tetr = malloc(sizeof(tetriminos_t) * nbr_files);
}
