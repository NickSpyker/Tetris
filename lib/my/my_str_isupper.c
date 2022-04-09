/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Return if the string is only upper or not
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z') {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
