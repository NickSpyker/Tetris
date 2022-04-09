/*
** EPITECH PROJECT, 2021
** my_showstr
** File description:
** print a string
*/

void my_putchar(char c);
int my_putnbr_base(int nbr , char const *base);

void display_zero(char const *str, int i)
{
    if (str[i] <= 16)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < 32) {
            my_putchar('\\');
            display_zero(str, i);
            my_putnbr_base(str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
        i += 1;
    }
    return (0);
}
