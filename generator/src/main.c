/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/generator.h"

int main(int ac, char **av)
{
    maze_t m;

    if (ac < 3 || !is_number(av[1]) || !is_number(av[2]) || ac > 4)
        return (84);
    if (ac == 4 && my_strncmp("perfect", av[3], 7) != 0)
        return (84);
    m.line = atoi(av[2]);
    m.cols = atoi(av[1]);
    srand(time(NULL));
    init_maze(&m);
    algo(&m);
    if (m.cell[2][2].type == 'X')
        get_exit(&m);
    if (ac == 3) {
        create_imperfect(&m, 0);
    }
    print_maze(&m);
    return (0);
}