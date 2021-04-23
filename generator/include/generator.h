/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct list_s {
    pos_t p;
    struct list_s *n;
} list_t;

typedef struct cell_s {
    char type;
    bool visit;
    int st;
} cell_t;

typedef struct maze_s {
    int line;
    int cols;
    cell_t **cell;
    list_t *list;
    bool testeur;
    size_t s_list;
} maze_t;

void go_top(maze_t *m, int rdm);
void print_maze(const maze_t *m);
void print_maze_debug(maze_t *m);
list_t *init_list(void);
void init_maze(maze_t *m);
bool tcheck_path(const maze_t *m, const pos_t p);
void list_push(list_t **list, pos_t p);
pos_t list_pop(list_t **list);
size_t list_size(list_t *list);
void go_right(maze_t *m, int rdm);
void go_left(maze_t *m, int rdm);
void go_bottom(maze_t *m, int rdm);
void go_top(maze_t *m, int rdm);
void algo(maze_t *m);
bool is_number(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
void my_putchar(char const c);
void my_putstr(char const *str);
unsigned long long rdtsc(void);
void get_exit(maze_t *m);
void create_imperfect(maze_t *m, int state);


# define TA_ALLOFF  "\033[00m"
# define TA_BOLD    "\033[01m"
# define TA_UNDERSCORE  "\033[04m"
# define TA_BLINK   "\033[05m"
# define TA_REVVIDEO    "\033[07m"
# define TA_CONCEALED   "\033[08m"

/*
**  FOREGROUND COLORS
*/

# define FG_BLACK   "\033[30m"
# define FG_RED     "\033[31m"
# define FG_GREEN   "\033[32m"
# define FG_YELLOW  "\033[33m"
# define FG_BLUE    "\033[34m"
# define FG_MAGENTA "\033[35m"
# define FG_CYAN    "\033[36m"
# define FG_WHITE   "\033[37m"

/*
**  BACKGROUND COLORS
*/

# define BG_BLACK   "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN   "\033[42m"
# define BG_YELLOW  "\033[43m"
# define BG_BLUE    "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN    "\033[46m"
# define BG_WHITE   "\033[47m"

# define BG_CLEAR   "\033[00m"

#endif /* !GENERATOR_H_ */