/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** display_game.c
*/

#include "tetris.h"

void all_game(game_t *gm)
{
    int x = (COLS - gm->window.x) / 2;
    int y = (LINES - gm->window.y) / 2;
    vect_t p = init_vect(28 + x, y);
    vect_t c_p = init_vect(p.x + gm->cur.pos.x + 1, p.y + gm->cur.pos.y + 1);

    erase();
    display_tetris_logo(init_vect(0 + x, 0 + y));
    display_square(init_vect(1 + x, 7 + y), init_vect(11, 25), COLOR_WHITE);
    display_square(p, init_vect(gm->size.y + 2, gm->size.x + 2), 7);
    display_array(gm->cur.tetrim, c_p);
    p.x += gm->size.x + 3;
    display_square(p, init_vect(7, 11), 7);
    mvprintw(y, p.x + 2, "next");
    display_info(gm, x, y);
    display_tetris(gm);
    display_next(gm, init_vect(p.x + 1, p.y + 1), gm->tetr);
    if (gm->end)
        display_end_message(gm);
    refresh();
}

void display_info(game_t *game, int x, int y)
{
    mvprintw(9 + y, 3 + x, "High Score");
    display_high_score(game->info, x, y);
    mvprintw(10 + y, 3 + x, "Score");
    mvprintw(10 + y, 24 + x - my_intlen(game->info.sco), "%i", game->info.sco);
    mvprintw(12 + y, 3 + x, "Line");
    mvprintw(12 + y, 24 + x - my_intlen(game->info.lin), "%i", game->info.lin);
    mvprintw(13 + y, 3 + x, "Level");
    mvprintw(13 + y, 24 + x - my_intlen(game->info.lvl), "%i", game->info.lvl);
    mvprintw(15 + y, 3 + x, "Timer");
    display_timer(game, 23 + x, 15 + y);
}

void display_timer(game_t *game, int x, int y)
{
    int min = game->info.tim / 60;
    int s = game->info.tim % 60;

    if (s < 10) {
        x = x - my_intlen(min) - my_intlen(s) - 1;
        mvprintw(y, x, "%i:0%i", min, s);
    } else
        mvprintw(y, x - my_intlen(min) - my_intlen(s), "%i:%i", min, s);
}

void display_high_score(info_t info, int x, int y)
{
    if (info.h_s <= info.sco)
        mvprintw(9 + y, 24 + x - my_intlen(info.sco), "%i", info.sco);
    else
        mvprintw(9 + y, 24 + x - my_intlen(info.h_s), "%i", info.h_s);
}

void display_end_message(game_t *game)
{
    int x = (COLS - game->window.x) / 2 + 31 + game->size.x;
    int y = (LINES - game->window.y) / 2 + 8;

    attron(COLOR_PAIR(COLOR_RED));
    mvprintw(y, x, "You lost...");
}
