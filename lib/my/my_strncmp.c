/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** reproduce the s_t_r_n_c_m_p function
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i += 1;
    }
    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (s1[i] - s2[i]);
    return (0);
}
