/*
** EPITECH PROJECT, 2021
** my_showmem
** File description:
** prints a memory dump
*/

int my_putnbr_base(int nbr , char const *base);
void my_putchar(char);

void display_str(char const *str, int index, int size)
{
    int i = 0;

    while (i < 16 && index + i < size) {
        if (str[index + i] < 32) {
            my_putchar('.');
        } else {
            my_putchar(str[index + i]);
        }
        i += 1;
    }
}

void display_mem(int line)
{
    int tamp = line;
    int count = 0;
    char base[] = "0123456789abcdef";

    while (tamp / 16 != 0) {
        count += 1;
        tamp /= 16;
    }
    for (int i = 7 - count; i > 0; i -= 1) {
        my_putchar('0');
    }
    my_putnbr_base(line, base);
    my_putchar(':');
    my_putchar(' ');
}

void display_full(int index, int count)
{
    int full = 16;
    int space = 8;

    for (int x = 0; x != full - index; x += 1) {
        my_putchar(' ');
        my_putchar(' ');
    }
    for (int y = 0; y != space - count; y += 1) {
        my_putchar(' ');
    }
}

void display_line(char const *str, int index, int size)
{
    char base[] = "0123456789abcdef";
    int i = 0;
    int count = 0;

    while (i < 16 && index + i < size) {
        if (str[index + i] <= 16) {
            my_putchar('0');
            my_putnbr_base(str[index + i], base);
        } else {
            my_putnbr_base(str[index + i], base);
        }
        if (i % 2 != 0) {
            my_putchar(' ');
            count += 1;
        }
        i += 1;
    }
    display_full(i, count);
}

int my_showmem(char const *str, int size)
{
    int line = 0;
    int i = 0;
    int max;

    if (size % 16 == 0) {
        max = size / 16;
    } else {
        max = size / 16 + 1;
    }
    while (line < max) {
        display_mem(i);
        display_line(str, i, size);
        display_str(str, i, size);
        my_putchar('\n');
        line += 1;
        i += 16;
    }
    return (0);
}
