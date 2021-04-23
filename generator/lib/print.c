/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** print_maze
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char const c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    size_t i = 0;

    for (;str[i]; i++) {
        my_putchar(str[i]);
    }
}

void print_maze2(char const **maze)
{
    size_t i = 0;

    for (;maze[i] != NULL; i++) {
        my_putstr(maze[i]);
        my_putchar('\n');
    }
}