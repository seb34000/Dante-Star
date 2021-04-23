/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** generate
*/

#include "../include/generator.h"

void algo2(const maze_t *m, int rdm)
{
    switch (rdm) {
    case 0:
        go_top(m, rdm);
        break;
    case 1:
        go_bottom(m, rdm);
        break;
    case 2:
        go_left(m, rdm);
        break;
    case 3:
        go_right(m, rdm);
        break;
    default:
        break;
    }
}

void set_list(maze_t *m)
{
    m->list->p.x = m->line + 1;
    m->list->p.y = m->cols + 1;
    m->cell[m->list->p.x][m->list->p.y].visit = true;
    m->cell[m->list->p.x][m->list->p.y].type = '*';
    m->s_list = list_size(m->list);
}

void algo(maze_t *m)
{
    int rdm = rand() % 3;
    int status = 0;

    set_list(m);
    do {
        srand(rdtsc());
        rdm = rand() % 4;
        if (m->cell[2][2].type != '*') {
            rdm = (rdm == 1) ? 0 : rdm;
            rdm = (rdm == 3) ? 2 : rdm;
        }
        algo2(m, rdm);
        if (m->list > 1 && m->list->p.x != 0 && m->list->p.y != 0 \
        && m->cell[m->list->p.x][m->list->p.y].st >= 4) {
            list_pop(&m->list);
            --m->s_list;
        }
        ++status;
    } while (status < (m->line * m->cols) - 1 );
}