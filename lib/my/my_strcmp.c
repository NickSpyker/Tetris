/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** reproduce the s_t_r_c_m_p function
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i += 1;
    }
    return (my_strlen(s1) - my_strlen(s2));
}
