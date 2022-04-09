/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** load_high_score.c
*/

#include "tetris.h"

static bool is_nbr(char *buffer)
{
    for (int i = 0; buffer[i]; i++)
        if (!('0' < buffer[i] && buffer[i] <= '9'))
            return false;
    return true;
}

static int load(char *buffer, game_t *game)
{
    int hs = my_getnbr(buffer);

    if (!is_nbr(buffer)) {
        free(buffer);
        my_putstr_err("ERROR; please remove content of 'high_score.txt'\n");
    }
    game->info.h_s = hs;
    free(buffer);
    return hs;
}

int load_high_score(game_t *game)
{
    int fd = open("data/high_score.txt", O_RDONLY);
    struct stat st;
    char *buffer;
    int hs;

    if (fd == -1)
        my_putstr_err("ERROR: please add 'high_score.txt' at 'data' folder\n");
    stat("data/high_score.txt", &st);
    if (st.st_size < 1) {
        close(fd);
        return 0;
    }
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';
    read(fd, buffer, st.st_size);
    close(fd);
    hs = load(buffer, game);
    return hs;
}
