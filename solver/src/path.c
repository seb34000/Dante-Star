/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** path.c
*/

#include "solver.h"

int count_path(var_t *v, int x, int y)
{
    int valid = 0;

    if (v->map[y - 1][x] == 1)
        valid += 1;
    if (v->map[y + 1][x] == 1)
        valid += 1;
    if (v->map[y][x - 1] == 1)
        valid += 1;
    if (v->map[y][x + 1] == 1)
        valid += 1;
    return (valid);
}

void check_move_path(var_t *v, int x, int y, int *state)
{
    if (*state == 0) {
        v->x = x;
        v->y = y;
    }
    *state += 1;
    if (*state > 1) {
        v->path[y][x] = 3;
    }
}

void move_path(var_t *v)
{
    int state = 0;
    int x = v->x;
    int y = v->y;

    if (y > 0 && v->path[y - 1][x] == 1)
        check_move_path(v, x, y - 1, &state);
    if (x > 0 && v->path[y][x - 1] == 1)
        check_move_path(v, x - 1, y, &state);
    if (x < v->column - 1 && v->path[y][x + 1] == 1)
        check_move_path(v, x + 1, y, &state);
    if (y < v->line - 1 && v->path[y + 1][x] == 1)
        check_move_path(v, x, y + 1, &state);
}

void reformat_path(var_t *v)
{
    v->path[v->line - 1][v->column - 1] = 1;
    v->path[v->y][v->x] = 2;
    while (v->x != v->column - 1 || v->y != v->line - 1) {
        move_path(v);
        v->path[v->y][v->x] = 2;
    }
    v->path[v->y][v->x] = 2;
    print_res(v);
}