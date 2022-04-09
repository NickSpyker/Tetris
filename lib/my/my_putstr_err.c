/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** my_putstr_err.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *str);

void my_putstr_err(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
}
