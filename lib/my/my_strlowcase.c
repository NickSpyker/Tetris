/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** puts every letter in lowercase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && 90 >= str[i]) {
            str[i] = str[i] + 32;
        }
        i += 1;
    }
    return (str);
}
