/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** concatenate n char of str into dest
*/

int my_strlen (char const *str);

char *my_strncat(char *dest , char const *src, int nb)
{
    int a = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && nb != 0) {
        dest[a + i] = src[i];
        i += 1;
        nb -= 1;
    }
    dest[a + i] = '\0';
    return (dest);
}
