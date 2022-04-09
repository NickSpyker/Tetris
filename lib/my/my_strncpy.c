/*
** EPITECH PROJECT, 2021
** my_strncopy
** File description:
** copy n string's character on another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i += 1;
    }
    while (i < n) {
        dest[i] = '\0';
        i += 1;
    }
    return (dest);
}
