/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** reproduce the strstr function
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int i_f = 0;

    while (str[i] != '\0' && to_find[i_f] != '\0') {
        if (str[i] == to_find[i_f]) {
            i_f += 1;
        } else if (i_f != 0){
            i_f = 0;
            continue;
        }
        i += 1;
    }
    if (to_find[i_f] != 0) {
        return (0);
    } else {
        return (str + i - i_f);
    }
}
