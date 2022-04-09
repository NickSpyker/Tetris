/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** display the content of an array of words
*/

void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);

int my_show_word_array(char const **tab)
{
    int nb = 0;

    while (tab[nb]) {
        my_putstr(tab[nb]);
        my_putchar('\n');
        nb += 1;
    }
    return (0);
}
