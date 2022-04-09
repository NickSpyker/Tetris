/*
** EPITECH PROJECT, 2021
** my_putnbr_base
** File description:
** display a nb in a base
*/

void my_putchar(char);
int my_strlen (char const *str);

void my_u_putnbr_base(unsigned long long int nbr , char const *base)
{
    unsigned long long int taille = my_strlen(base);

    if (nbr < taille) {
        my_putchar(base[nbr]);
    } else {
        my_u_putnbr_base(nbr / taille, base);
        my_u_putnbr_base(nbr % taille, base);
    }
}

void my_putnbr_base(long long int nbr , char const *base)
{
    long long int taille = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        if (-(nbr / taille) != 0) {
            my_putnbr_base(-(nbr / taille), base);
        }
        my_putchar(base[-(nbr % taille)]);
    } else if (nbr < taille) {
        my_putchar(base[nbr]);
    } else {
        my_putnbr_base(nbr / taille, base);
        my_putnbr_base(nbr % taille, base);
    }
}
