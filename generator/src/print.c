/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** print
*/

#include "../include/generator.h"

inline void print_wall(char c)
{
    write(1, &c, 1);
}

inline void print_path(char c)
{
    write(1, &c, 1);
}

void print_maze(const maze_t *m)
{
    for (int i = 2; i < m->line + 2; i++) {
        for (int j = 2; j < m->cols + 2; j++) {
            (m->cell[i][j].type == 'X') ? print_wall(m->cell[i][j].type) : NULL;
            (m->cell[i][j].type == '*') ? print_path(m->cell[i][j].type) : NULL;
        }
        (i > 1 && i < m->line + 1) ? write(1, "\n", 1) : NULL;
    }
}

void print_maze_debug(maze_t *m)
{
    for (int i = 0; i < m->line + 4; i++) {
        for (int j = 0; j < m->cols + 4; j++) {
            write(1, &m->cell[i][j].type, 1);
        }
        write(1, "\n", 1);
    }
}