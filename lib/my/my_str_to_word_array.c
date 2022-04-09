/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str);

int verif_alphanum(char c)
{
    if ((48 <= c && c <= 57) || (65 <= c && c <= 90) || (97 <= c && c <= 122))
        return (0);
    return (1);
}

char *new_word(char *dest, char const *src)
{
    int i = 0;
    int verif = verif_alphanum(src[i]);

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (verif == 0) {
        dest[i] = src[i];
        i += 1;
        verif = verif_alphanum(src[i]);
    }
    dest[i] = '\0';
    return (dest);
}

char **my_str_to_word_array(char const *str)
{
    char *tamp;
    char **array;
    int i = 0;
    int nb = 0;

    array = malloc(sizeof(char *) * my_strlen(str));
    while (i < my_strlen(str)) {
        tamp = new_word(tamp, &str[i]);
        if (my_strlen(tamp) != 0) {
            array[nb] = tamp;
            nb += 1;
        }
        i += my_strlen(tamp) + 1;
    }
    array[nb] = NULL;
    return (array);
}
