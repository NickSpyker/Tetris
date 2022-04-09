/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** Return if the string is only printable or not
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (32 <= str[i]) {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
