/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** perfect_maze
*/

#include "../include/generator.h"

void create_cell(maze_t *m, int i, int j)
{
    if (j == 0 || j == 1 || i == 0 || i == 1 \
    || i >= m->line + 2 || j >= m->cols + 2) {
        m->cell[i][j].type = '0';
        m->cell[i][j].visit = false;
        m->cell[i][j].st = 0;
    } else {
        m->cell[i][j].type = 'X';
        m->cell[i][j].visit = false;
        m->cell[i][j].st = 0;
    }
}

void init_maze(maze_t *m)
{
    m->testeur = true;
    m->list = init_list();
    m->cell = malloc(sizeof(cell_t *) * (m->line + 4));
    memset(m->cell, 0, sizeof(cell_t *) * (m->line + 4));
    for (int i = 0; i < m->line + 4; ++i) {
        m->cell[i] = malloc(sizeof(cell_t) * (m->cols + 4));
        memset(m->cell[i], 0, sizeof(cell_t) * (m->cols + 4));
        for (int j = 0; j < m->cols + 4; ++j) {
            create_cell(m, i, j);
        }
    }
}

bool tcheck_path(const maze_t *m, const pos_t p)
{
    int state = 0;

    if (m->cell[p.x + 1][p.y].type == '*')
        state++;
    if (m->cell[p.x - 1][p.y].type == '*')
        state++;
    if (m->cell[p.x][p.y + 1].type == '*')
        state++;
    if (m->cell[p.x][p.y - 1].type == '*')
        state++;
    if (state >= 2)
        return (false);
    return (true);
}