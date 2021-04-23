/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** enter_exit
*/

#include "../include/generator.h"

void rec_exit(maze_t *m, int x, int y)
{
    int rdm = rand() % 2 + 1;

    if (m->cell[x][y].visit == true)
        return ;
    else {
        m->cell[x][y].visit = true;
        m->cell[x][y].type = '*';
    }
    if (rdm == 1) {
        x++;
        rec_exit(m, x, y);
    } else {
        y++;
        rec_exit(m, x, y);
    }

}

void get_exit(maze_t *m)
{
    int x = 2;
    int y = 2;

    if (m->cell[x][y].type != '*') {
        rec_exit(m, x, y);
    }
}