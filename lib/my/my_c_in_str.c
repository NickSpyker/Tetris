/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-clarisse.eynard
** File description:
** my_c_in_str.c
*/

int my_c_in_str(char c, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}
