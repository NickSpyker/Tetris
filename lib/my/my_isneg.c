/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** display N if negativ, P if positiv or nul
*/

void my_putchar(char);

int my_isneg(int n)
{
    char neg = 'N';
    char pos = 'P';

    if (n < 0) {
        my_putchar(neg);
    } else {
        my_putchar(pos);
    }
    my_putchar('\n');
    return (0);
}
