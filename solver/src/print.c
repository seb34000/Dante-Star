/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** print.c
*/

#include "solver.h"

void check_print_bonus(var_t *v, int x, int y)
{
    if (v->path[y][x] == 0 || v->path[y][x] == 1 || v->path[y][x] == 3) {
        write(1, FG_WHITE, 6);
        write(1, "*", 1);
        write(1, BG_CLEAR, 6);
    }
    if (v->path[y][x] == 2) {
        write(1, FG_GREEN, 6);
        write(1, "o", 1);
        write(1, BG_CLEAR, 6);
    }
    if (v->path[y][x] == 9) {
        write(1, FG_RED, 6);
        write(1, "X", 1);
        write(1, BG_CLEAR, 6);
    }
}

void check_print(var_t *v, int x, int y)
{
    if (v->path[y][x] == 0 || v->path[y][x] == 1 || v->path[y][x] == 3)
        write(1, "*", 1);
    if (v->path[y][x] == 2)
        write(1, "o", 1);
    if (v->path[y][x] == 9)
        write(1, "X", 1);
}

void print_res(var_t *v)
{
    for (int y = 0; y < v->line; y += 1) {
        for (int x = 0; x < v->column; x += 1)
            check_print(v, x, y);
        if (y < v->line - 1)
            write(1, "\n", 1);
    }
}