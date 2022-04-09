/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** puts every letter in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 97 && 122 > str[i]) {
            str[i] = str[i] - 32;
        }
        i += 1;
    }
    return (str);
}
