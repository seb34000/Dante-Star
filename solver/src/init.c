/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** init.c
*/

#include "solver.h"

int check_map(var_t *v, int *x, int *y, char c)
{
    if (c == '*') {
        v->map[*y][*x] = 0;
        *x += 1;
        return (0);
    }
    if (c == 'X') {
        v->state = 1;
        v->map[*y][*x] = 9;
        *x += 1;
        return (0);
    }
    if (c == '\n') {
        *x = 0;
        *y += 1;
        if (*y < v->line)
            v->map[*y] = calloc(v->column, sizeof(int));
        return (0);
    }
    return (-1);
}

int init_map(var_t *v, char *buff)
{
    int x = 0;
    int y = 0;

    for (v->column = 0; buff[v->column] != '\n'; v->column += 1);
    v->line = 0;
    for (int i = v->column; buff[i] != '\0'; i += v->column + 1) {
        if (buff[i] == '\n')
            v->line++;
    }
    v->line++;
    v->state = 0;
    v->map = calloc(v->line, sizeof(int *));
    v->map[0] = calloc(v->column, sizeof(int));
    for (int i = 0; buff[i] != '\0'; i += 1) {
        if (x > v->column)
            return (-1);
        if (check_map(v, &x, &y, buff[i]) == -1)
            return (-1);
    }
    return (0);
}

int read_map(var_t *v, char *path)
{
    int fd = open(path, O_RDONLY);
    int size = lseek(fd, 0L, SEEK_END);
    char *buff = malloc(sizeof(char) * size + 1);

    lseek(fd, 0L, SEEK_SET);
    if (read(fd, buff, size) == -1) {
        free(buff);
        return (-1);
    }
    buff[size] = '\0';
    if (init_map(v, buff) == -1)
        return (-1);
    free(buff);
    return (0);
}

int init(var_t *v, char *path)
{
    if (read_map(v, path) == -1)
        return (-1);
    v->cursor = calloc(v->line, sizeof(int *));
    for (int i = 0; i < v->line; i += 1) {
        v->cursor[i] = calloc(v->column, sizeof(int));
    }
    v->path = calloc(v->line, sizeof(int *));
    for (int i = 0; i < v->line; i += 1) {
        v->path[i] = calloc(v->column, sizeof(int));
        for (int ii = 0; ii < v->column; ii += 1)
            v->path[i][ii] = v->map[i][ii];
    }
    v->x = 0;
    v->y = 0;
    return (0);
}