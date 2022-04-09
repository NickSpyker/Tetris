/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** error_handling.c
*/

#include "tetris.h"

static bool is_number(char *str)
{
    bool result = true;

    for (int i = 0; str[i]; i++) {
        if ('0' <= str[i] && str[i] <= '9')
            continue;
        result = false;
    }
    return result;
}

static bool is_allowed_simple(char *str)
{
    char allowed[9] = "LlrtdqpwD";
    bool result = false;

    if (my_strlen(str) < 2)
        return result;
    if (str[0] != '-' || str[1] == '-')
        return result;
    for (int i = 1; str[i]; i++) {
        result = false;
        for (int j = 0; j < 9; j++)
            result = str[i] == allowed[j] ? true : result;
        if (!result)
            break;
    }
    return result;
}

static bool is_compatible(char *str)
{
    char type[7] = "Llrtdqp";
    int count = 0;

    for (int i = 0; str[i]; i++)
        for (int j = 0; j < 7; j++)
            count += str[i] == type[j] ? 1 : 0;
    return count < 2 ? true : false;
}

static bool is_nbr_for_arg(char **str, int args, int nb_args)
{
    char type[7] = "Llrtdqp";
    bool is_in_type = false;

    for (int i = 0; str[args][i]; i++)
        for (int j = 0; j < 7; j++)
            is_in_type = str[args][i] == type[j] ? true : is_in_type;
    if (!is_in_type)
        return args < nb_args - 1 ? !is_number(str[args + 1]) : true;
    if (args < nb_args - 2)
        if (is_number(str[args + 2]))
            return false;
    return args < nb_args - 1 ? is_number(str[args + 1]) : false;
}

void error_handling(int argc, char *argv[])
{
    bool not_compatible = false;

    if (argc < 2)
        return;
    if (is_number(argv[1]))
        my_putstr_err("ERROR: Wrong argument !\n");
    for (int i = 1; i < argc; i++) {
        if (is_number(argv[i]))
            continue;
        if (is_compatible(argv[i]) && is_allowed_simple(argv[i]) && \
        is_nbr_for_arg(argv, i, argc))
            continue;
        if (my_strlen(argv[i]) > 2 ? argv[i][0] == '-' \
        && argv[i][1] == '-' : true)
            continue;
        my_putstr_err("ERROR: Wrong argument !\n");
    }
}
