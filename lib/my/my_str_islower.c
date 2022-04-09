/*
** EPITECH PROJECT, 2021
** my_str_islower
** File description:
** Return if the string is only lower or not
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('a' <= str[i] && str[i] <= 'z') {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
