/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** Return if the string is only num or not
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('0' <= str[i] && str[i] <= '9') {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
