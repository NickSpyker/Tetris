/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** tetri_pars.c
*/

#include "tetris.h"

static int tetriminos_error_handling(char *buffer)
{
    bool temp = true;

    for (int i = 0; buffer[i]; i++) {
        temp = buffer[i] == '\n' ? false : temp;
        if (temp && (buffer[i] < '0' || '9' < buffer[i]) && buffer[i] != ' ') {
            free(buffer);
            return EXIT_FAILURE;
        }
        if (!temp && buffer[i] != ' ' && buffer[i] != '*' && \
        buffer[i] != '\n') {
            free(buffer);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static tetriminos_t *fill_form(tetriminos_t *tetri, char *buffer)
{
    bool start_fill = false;
    int x = -1;
    int y = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n') {
            start_fill = true;
            y = 0;
            x++;
            continue;
        }
        if (buffer[i] == '*' && start_fill)
            tetri->form[x][y] = '*';
        y++;
    }
    free(buffer);
    return tetri;
}

static tetriminos_t *create_form(tetriminos_t *tetri, char *buffer)
{
    for (int i = 0; i < tetri->size; i++) {
        tetri->form[i] = malloc(sizeof(char) * (tetri->size + 1));
        tetri->form[i][tetri->size] = '\0';
        for (int j = 0; j < tetri->size; j++)
            tetri->form[i][j] = ' ';
    }
    return fill_form(tetri, buffer);
}

static tetriminos_t *malloc_and_fill_tetriminos(char *buffer)
{
    tetriminos_t *tetri = malloc(sizeof(tetriminos_t));

    *tetri = (tetriminos_t){NULL, NULL, 0, 0, 0, 0, false};
    if (tetriminos_error_handling(buffer)) {
        return tetri;
    } else
        tetri->valid = true;
    for (int i = 0; buffer[i] && buffer[i] != '\n'; i++) {
        if (tetri->nbr_cols == 0 && ('0' <= buffer[i] && buffer[i] <= '9'))
            tetri->nbr_cols = my_getnbr_parsing(&i, buffer);
        if (tetri->nbr_rows == 0 && ('0' <= buffer[i] && buffer[i] <= '9'))
            tetri->nbr_rows = my_getnbr_parsing(&i, buffer);
        if (tetri->color == 0 && ('0' <= buffer[i] && buffer[i] <= '9'))
            tetri->color = my_getnbr_parsing(&i, buffer);
    }
    tetri->size = tetri->nbr_cols < tetri->nbr_rows ? \
    tetri->nbr_rows : tetri->nbr_cols;
    tetri->form = malloc(sizeof(char *) * (tetri->size + 1));
    tetri->form[tetri->size] = NULL;
    return create_form(tetri, buffer);
}

tetriminos_t *tetri_pars(char *path_to_file)
{
    int fd = open(path_to_file, O_RDONLY);
    struct stat st;
    char *buffer;

    if (fd == -1)
        my_putstr_err("ERROR: wrong path to file for tetriminos parsing !");
    stat(path_to_file, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';
    read(fd, buffer, st.st_size);
    close(fd);
    return malloc_and_fill_tetriminos(buffer);
}
