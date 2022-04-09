/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** put every first letter in capitalize
*/

char *strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && 90 >= str[i]) {
            str[i] = str[i] + 32;
        }
        i += 1;
    }
    return (str);
}

int verif_al_num(char c)
{
    if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) {
        return (0);
    } else if (48 <= c && c <= 57) {
        return (2);
    }
    return (1);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    str = strlowcase(str);
    if ('a' <= str[0] && str[0] <= 'z') {
        str[0] -= 32;
    }
    while (str[i] != '\0') {
        if (verif_al_num(str[i - 1]) == 1 && verif_al_num(str[i]) == 0) {
            str[i] -= 32;
        }
        i += 1;
    }
    return (str);
}
