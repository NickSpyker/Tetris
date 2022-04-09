/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** display.c
*/

#include "tetris.h"

void display_length(vect_t vect, int len, char left, char rigth)
{
    mvprintw(vect.y, vect.x, "%c", left);
    for (int i = 0; i < len - 2; i++)
        printw("-");
    printw("%c", rigth);
}

void display_square(vect_t vect, vect_t size, int color)
{
    attron(COLOR_PAIR(color));
    display_length(vect, size.y, '/', '\\');
    printw("\n");
    for (int i = 0; i < size.x - 2; i++) {
        vect.y++;
        mvprintw(vect.y, vect.x, "|");
        for (int i = 0; i < size.y - 2; i++)
            printw(" ");
        printw("|\n");
    }
    vect.y++;
    display_length(vect, size.y, '\\', '/');
    attroff(COLOR_PAIR(color));
}

void display_t_letter(vect_t vect, int color)
{
    attron(COLOR_PAIR(color));
    mvprintw(vect.y, vect.x, "* * *");
    for (int i = 1; i < 5; i++)
        mvprintw(vect.y + i, vect.x, "  *\n");
    attroff(COLOR_PAIR(color));
}

void display_ris(vect_t vect)
{
    attron(COLOR_PAIR(COLOR_MAGENTA));
    mvprintw(vect.y, vect.x, "* * *\n");
    mvprintw(vect.y + 1, vect.x, "*   *\n");
    mvprintw(vect.y + 2, vect.x, "* *\n");
    mvprintw(vect.y + 3, vect.x, "*   *\n");
    mvprintw(vect.y + 4, vect.x, "*   *\n");
    attron(COLOR_PAIR(COLOR_CYAN));
    vect.x += 5;
    mvprintw(vect.y, vect.x, "*\n");
    mvprintw(vect.y + 2, vect.x, "*\n");
    mvprintw(vect.y + 3, vect.x, "*\n");
    mvprintw(vect.y + 4, vect.x, "*\n");
    attron(COLOR_PAIR(COLOR_YELLOW));
    mvprintw(vect.y, vect.x + 1, "* * *\n");
    mvprintw(vect.y + 1, vect.x + 1, "*\n");
    mvprintw(vect.y + 2, vect.x + 1, "* * *\n");
    mvprintw(vect.y + 3, vect.x + 1, "    *\n");
    mvprintw(vect.y + 4, vect.x + 1, "* * *\n");
}

void display_tetris_logo(vect_t vect)
{
    display_t_letter(vect, COLOR_RED);
    attron(COLOR_PAIR(COLOR_BLUE));
    vect.x += 5;
    mvprintw(vect.y, vect.x, "* * *\n");
    mvprintw(vect.y + 1, vect.x, "*\n");
    mvprintw(vect.y + 2, vect.x, "* *\n");
    mvprintw(vect.y + 3, vect.x, "*\n");
    mvprintw(vect.y + 4, vect.x, "* * *\n");
    vect.x += 5;
    display_t_letter(vect, COLOR_GREEN);
    vect.x += 5;
    display_ris(vect);
    attron(COLOR_PAIR(COLOR_WHITE));
}
