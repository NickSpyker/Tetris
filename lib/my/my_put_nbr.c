/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

void my_putchar(char);

void my_u_put_nbr(unsigned long long int nb)
{
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_u_put_nbr(nb / 10);
        my_u_put_nbr(nb % 10);
    }
}

void my_put_nbr(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (-(nb / 10) != 0) {
            my_put_nbr(-(nb / 10));
        }
        my_putchar(-(nb % 10) + 48);
    } else if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}
