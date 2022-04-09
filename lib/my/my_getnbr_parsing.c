/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** my_getnbr_parsing.c
*/

int my_getnbr_parsing(int *start, char *str)
{
    int result = 0;

    for (int i = *start; str[i]; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            result *= 10;
            result += str[i] - '0';
            *start += 1;
            continue;
        }
        break;
    }
    return result;
}
