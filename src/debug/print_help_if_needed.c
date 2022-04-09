/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** print_help_if_needed.c
*/

#include "tetris.h"

void print_help_if_needed(int argc, char *argv[], bool act)
{
    int fd;
    char *buffer;
    struct stat st;

    if (argc < 2)
        return;
    if (my_strcmp(argv[1], "--help") && !act)
        return;
    fd = open("data/help.txt", O_RDONLY);
    if (fd == -1)
        my_putstr_err("ERROR:\tWrong path to file !\n");
    stat("data/help.txt", &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';
    read(fd, buffer, st.st_size);
    close(fd);
    write(1, buffer, my_strlen(buffer));
    free(buffer);
    exit(0);
}
