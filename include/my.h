/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-bsmyls-clarisse.eynard
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

int my_isneg(int nb);
void my_putchar(char c);
int my_is_prime(int nb);
int verif_alphanum(char c);
char *my_revstr(char *str);
void my_put_tab(char **tab);
char *my_int_to_str(int nb);
void my_swap(int *a, int *b);
void my_putstr_err(char *str);
int my_find_prime_sup(int nb);
char *my_strupcase(char *str);
int my_arraylen(char **array);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strlowcase(char *str);
int my_showstr(char const *str);
int my_intlen(long long int nb);
char *my_strdup(char const *src);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
void my_put_nbr(long long int nb);
int my_compute_square_root(int nb);
char **my_array_alloc(int x, int y);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *my_malloc_strcpy(char const *src);
int my_str_isprintable(char const *str);
int my_show_word_array(char const **tab);
int my_c_in_str(char c, char const *str);
int my_showmem(char const *str, int size);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
char *new_word(char *dest, char const *src);
char *concat_params(int argc , char **argv);
int my_getnbr_parsing(int *start, char *str);
void my_u_put_nbr(unsigned long long int nb);
char **my_str_to_word_array(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strstr(char *str, char const *to_find);
char *my_strcat(char const *deb, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncat(char *dest, char const *src, int nb);
void my_putnbr_base(long long int nbr , char const *base);
void my_u_putnbr_base(unsigned long long int nbr , char const *base);

#endif
