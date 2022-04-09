/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** returns the smallest prime number
*/

int is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    while (i != nb) {
        if (nb % i == 0)
            return (0);
        i += 1;
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int i = nb + 1;

    if (is_prime(nb) == 1)
        return (nb);
    while (is_prime(i) == 0) {
        i += 1;
    }
    return (i);
}
