/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** debug_sd.c
*/

#include "tetris.h"

char *debug_sd(int n)
{
    char *str = malloc(sizeof(char) * 2);

    str[1] = '\0';
    str[0] = (char)n;
    return str;
}
