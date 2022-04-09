/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** set_high_score.c
*/

#include "tetris.h"

static char *nbt_to_str(int nbr)
{
    int temp = nbr;
    int size = 1;
    char *str;

    while (temp / 10 != 0) {
        size++;
        temp /= 10;
    }
    str = malloc(sizeof(char) * (size + 1));
    str[size] = '\0';
    temp = nbr;
    for (int i = size - 1; i >= 0; i--) {
        str[i] = temp % 10 + '0';
        temp /= 10;
    }
    return str;
}

void set_high_score(game_t *game, int score)
{
    int last_high_score = load_high_score(game);
    char *str_score;
    int fd;

    if (score < last_high_score)
        return;
    fd = open("data/high_score.txt", O_WRONLY);
    str_score = nbt_to_str(score);
    write(fd, str_score, my_strlen(str_score));
    close(fd);
    free(str_score);
}
