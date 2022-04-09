/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a string
*/

int my_strlen (char const *str);

char *my_revstr(char *str)
{
    int deb = 0;
    int end = my_strlen(str) - 1;
    char tamp;

    while (deb < end) {
        tamp = str[deb];
        str[deb] = str[end];
        str[end] = tamp;
        deb += 1;
        end -= 1;
    }
    return (str);
}
