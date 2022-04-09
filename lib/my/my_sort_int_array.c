/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

int *swap(int *tab, int k)
{
    int tamp;

    if (tab[k] < tab[k - 1]) {
        tamp = tab[k];
        tab[k] = tab[k - 1];
        tab[k - 1] = tamp;
    }
    return (tab);
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i += 1) {
        for (int k = size - 1; k > i; k -= 1) {
            tab = swap(tab, k);
        }
    }
}
