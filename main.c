/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** main.c
*/

#include "tetris.h"

int main(int ac, char **av)
{
    game_t game;

    print_help_if_needed(ac, av, false);
    error_handling(ac, av);
    fill_path_to_files_tetriminos(&game);
    load_high_score(&game);
    debug_mode(ac, av, &game);
    mv_start_to_nbr(&game);
    init_game(&game);
    tetris(&game);
    return 0;
}
