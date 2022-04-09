/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-tetris-clarisse.eynard
** File description:
** tetris.h
*/

#ifndef TETRIS_H
    #define TETRIS_H

    #include "my.h"
    #include <pwd.h>
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <getopt.h>
    #include <ncurses.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/types.h>

enum direct {
    rigth = 1,
    left = -1,
};

typedef struct opt_s {
    bool level;
    bool key_left;
    bool key_right;
    bool key_turn;
    bool key_drop;
    bool key_quit;
    bool key_pause;
} opt_t;

typedef struct s_vect {
    int x;
    int y;
} vect_t;

typedef struct t_key_s {
    int right;
    int pause;
    int left;
    int turn;
    int drop;
    int quit;
} t_key_t;

static struct option long_options[] = {
    {"level", required_argument, 0, 'L'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {"map-size", required_argument, 0, 'M'},
    {"without-next", no_argument, 0, 'w'},
    {"debug", no_argument, 0, 'D'},
    {0, 0, 0, 0}
};

typedef struct s_tetriminos {
    char **form;
    char *name;
    int nbr_rows;
    int nbr_cols;
    int color;
    int size;
    bool valid;
} tetriminos_t;

typedef struct info_s {
    int tim;
    int lin;
    int sco;
    int h_s;
    int lvl;
} info_t;

typedef struct s_current {
    vect_t cur_next;
    char **tetrim;
    vect_t x_site;
    vect_t y_site;
    bool rotate;
    vect_t pos;
    bool down;
    int size;
} current_t;

typedef struct game_s {
    char **path_to_all_tetriminos;
    tetriminos_t *tetr;
    current_t cur;
    int nb_tetrim;
    vect_t window;
    t_key_t key;
    char **area;
    vect_t size;
    info_t info;
    bool pause;
    bool next;
    bool end;
} game_t;

void tetris(game_t *game);

// Graphic

void init_ncurse(void);
void all_game(game_t *game);
void display_ris(vect_t pos);
void init_game(game_t *game);
void size_handle(game_t *game);
void display_tetris(game_t *game);
void display_tetris_logo(vect_t pos);
void display_end_message(game_t *game);
void exit_ncurse(game_t *game, int end);
void display_t_letter(vect_t pos, int color);
void display_info(game_t *game, int x, int y);
void display_array(char **tetrim, vect_t pos);
void display_timer(game_t *game, int x, int y);
void display_high_score(info_t info, int x, int y);
void display_square(vect_t pos, vect_t size, int color);
void display_length(vect_t pos, int len, char left, char rigth);
void display_menu(game_t *game, clock_t *begin, clock_t *start);
void display_next(game_t *game, vect_t pos, tetriminos_t *tetrim);
int menu_key(game_t *game, int key, clock_t *begin, clock_t *start);

// Tetris

void defeat(game_t *game);
char **rotate(char **tetrim);
void tetris_norme(game_t *game);
void increase_level(game_t *game);
void get_current_site(current_t *cur);
void drop(game_t *game, current_t *cur);
char **remplace_area(char **area, int line);
char **get_current_form(tetriminos_t tetrim);
void pause_game(game_t *game, clock_t *start);
void can_rotate(game_t *game, current_t *cur);
void can_go_down(game_t *game, current_t *cur);
bool can_move_left(game_t *gm, current_t *cur);
bool can_move_rigth(game_t *gm, current_t *cur);
void get_cur_y_site(current_t *cur, int i, int j);
void get_cur_x_site(current_t *cur, int i, int j);
void tetrim_go_down(game_t *game, current_t *cur);
void tetrim_to_area(game_t *game, current_t *cur);
char **verif_complete_line(game_t *game, char **area);
void key_handle(game_t *game, int key, clock_t *start);
void move_tetrim(game_t *game, current_t *cur, int direct);
void clock_handle(clock_t begin, clock_t *start, game_t *game);
void go_down_norme(game_t *game, current_t *cur, int i, int j);
void init_current_info(current_t *cur, tetriminos_t *tetrim, game_t *gm);
void t_to_area_norme(game_t *game, current_t *cur, char current, vect_t vect);

// Gebug

char *debug_sd(int n);
char *get_name(char *str);
int get_loc(char c, char *str);
vect_t init_vect(int x, int y);
int load_high_score(game_t *game);
void mv_start_to_nbr(game_t *game);
void write_this(char *str, int nbr);
void error_handling(int argc, char *argv[]);
void set_high_score(game_t *game, int score);
tetriminos_t *tetri_pars(char *path_to_file);
int get_opt_int(char c, char **argv, int argc);
void write_this_x_two(char *str_a, char *str_b);
void fill_path_to_files_tetriminos(game_t *game);
void debug_mode(int argc, char *argv[], game_t *game);
void print_help_if_needed(int argc, char *argv[], bool act);
void fill_opt_args(game_t *game, opt_t opt, char **argv, int argc);
void get_all_opt(game_t *game, bool *debug_mode, int argc, char *argv[]);
void print_tetriminos(bool valid, char **str, int nbr_rows, int nbr_cols);
void get_all_long_opt(game_t *game, bool *debug_mode, int argc, char *argv[]);

#endif
