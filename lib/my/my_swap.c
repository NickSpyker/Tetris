/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swaps the content of 2 integers
*/

void my_swap(int *a, int *b)
{
    int tamp1 = *a;
    int tamp2 = *b;

    *a = tamp2;
    *b = tamp1;
}
