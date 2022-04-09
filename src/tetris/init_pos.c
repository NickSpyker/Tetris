/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** init_vect.c
*/

#include "tetris.h"

vect_t init_vect(int x, int y)
{
    vect_t vect;

    vect.x = x;
    vect.y = y;
    return vect;
}
