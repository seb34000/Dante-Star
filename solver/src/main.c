/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** main.c
*/

#include "solver.h"

void destroy(var_t *v)
{
    for (int i = 0; i < v->line; i += 1)
        free(v->map[i]);
    free(v->map);
    for (int i = 0; i < v->line; i += 1)
        free(v->cursor[i]);
    free(v->cursor);
    for (int i = 0; i < v->line; i += 1)
        free(v->path[i]);
    free(v->path);
}

int main(int argc, char **argv)
{
    var_t var;

    if (init(&var, argv[1]) == -1)
        return (84);
    screen(&var);
    destroy(&var);
    return (0);
}