/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** debug_tools.c
*/

#include "tetris.h"

void write_this(char *str, int nbr)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '?')
            my_put_nbr(nbr);
        else
            write(1, &str[i], 1);
    }
}

void write_this_x_two(char *str_a, char *str_b)
{
    write(1, str_a, my_strlen(str_a));
    write(1, str_b, my_strlen(str_b));
}

static void is_good(char *str, int i)
{
    bool write_this = false;

    for (int j = i; str[j]; j++)
        if (str[j] != ' ')
            write_this = true;
    if (write_this)
        write(1, &str[i], 1);
}

void print_tetriminos(bool valid, char **str, int nbr_rows, int nbr_cols)
{
    if (!valid)
        return;
    for (int i = 0; i < nbr_rows; i++) {
        for (int j = 0; j < nbr_cols; j++) {
            is_good(str[i], j);
        }
        write(1, "\n", 1);
    }
}

char *get_name(char *str)
{
    int stop = my_strlen(str) - 1;
    int start = 0;
    char *result;

    for (int i = 0; str[i]; i++) {
        stop = str[i] == '.' ? i : stop;
        start = str[i] == '/' ? (str[i + 1] != '\0' ? i + 1 : start) : start;
    }
    result = malloc(sizeof(char) * (stop - start + 1));
    result[stop - start] = '\0';
    for (int i = start; i < stop; i++)
        result[i - start] = str[i];
    return result;
}
