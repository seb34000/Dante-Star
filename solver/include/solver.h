/*
** EPITECH PROJECT, 2021
** Dante
** File description:
** solver.h
*/

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct var_s {
    int **map;
    int **cursor;
    int **path;
    int column;
    int line;
    int x;
    int y;
    int state;
} var_t;

int init(var_t *v, char *path);
void screen(var_t *v);
void reformat_path(var_t *v);
void print_res(var_t *v);

# define FG_RED     "\033[31m"
# define FG_GREEN   "\033[32m"
# define FG_WHITE   "\033[37m"

# define BG_CLEAR   "\033[00m"

#endif