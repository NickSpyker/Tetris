/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** return the square root if it's a whole number of the argument
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 0 || nb == 0) {
        return (0);
    } else if (nb == 1) {
        return (1);
    }
    while (i != nb) {
        if (i * i == nb)
            return (i);
        i += 1;
    }
    return (0);
}
