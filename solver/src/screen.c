/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** screen.c
*/

#include "solver.h"

int set_path(var_t *v, int x, int y)
{
    v->path[y][x] = 1;
    return (1);
}

int solve_rec(var_t *v, int x, int y)
{
    if (x == v->column - 1 && y == v->line - 1)
        return (1);
    if (v->map[y][x] > 0 || v->cursor[y][x] > 0)
        return (0);
    v->cursor[y][x] = 1;
    if (x != v->column - 1)
        if (solve_rec(v, x + 1, y) == 1)
            return (set_path(v, x, y));
    if (y != v->line - 1)
        if (solve_rec(v, x, y + 1) == 1)
            return (set_path(v, x, y));
    if (x != 0)
        if (solve_rec(v, x - 1, y) == 1)
            return (set_path(v, x, y));
    if (y != 0)
        if (solve_rec(v, x, y - 1) == 1)
            return (set_path(v, x, y));
    return (0);
}

int check_path(var_t *v)
{
    for (int i = 0; i < v->line; i++)
        v->path[i][0] = 2;
    for (int i = 0; i < v->column; i++)
        v->path[v->line - 1][i] = 2;
    print_res(v);
}

void screen(var_t *v)
{
    if (v->state == 0) {
        check_path(v);
        return;
    }
    if (solve_rec(v, 0, 0) == 0)
        printf("no solution found\n");
    else
        reformat_path(v);
}
