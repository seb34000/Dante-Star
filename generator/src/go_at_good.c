/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** go_at
*/

#include "../include/generator.h"

void go_right(maze_t *m, int rdm)
{
    pos_t p = {0, 0};

    p.x = m->list->p.x;
    p.y = m->list->p.y;
    if (m->cell[m->list->p.x][m->list->p.y].st >= 4)
        return;
    if (rdm == 3 && m->list->p.y + 1 < m->cols + 2 && m->cell[m->list->p.x] \
    [m->list->p.y + 1].type != '0' && m->cell[m->list->p.x][m->list->p.y + 1] \
    .visit == false && m->cell[m->list->p.x][m->list->p.y + 2].visit == false \
    && tcheck_path(m, (pos_t){p.x, p.y + 1})) {
        ++p.y;
        m->cell[p.x][p.y].visit = true;
        m->cell[p.x][p.y].type = '*';
        list_push(&m->list, p);
        ++m->s_list;
    } else {
        rdm = 0;
        m->cell[m->list->p.x][m->list->p.y].st++;
        go_top(m, rdm);
    }
}

void go_left(maze_t *m, int rdm)
{
    pos_t p = {0, 0};

    p.x = m->list->p.x;
    p.y = m->list->p.y;
    if (m->cell[m->list->p.x][m->list->p.y].st >= 4)
        return;
    if (rdm == 2 && m->list->p.y - 1 > 1 && m->cell[m->list->p.x][m->list-> \
    p.y - 1].type != '0' && m->cell[m->list->p.x][m->list->p.y - 1].visit == \
    false && m->cell[m->list->p.x][m->list->p.y - 2].visit == false && \
    tcheck_path(m, (pos_t){p.x, p.y - 1})) {
        --p.y;
        m->cell[p.x][p.y].visit = true;
        m->cell[p.x][p.y].type = '*';
        list_push(&m->list, p);
        ++m->s_list;
    } else {
        rdm = 3;
        m->cell[m->list->p.x][m->list->p.y].st++;
        go_right(m, rdm);
    }
}

void go_bottom(maze_t *m, int rdm)
{
    pos_t p = {0, 0};

    p.x = m->list->p.x;
    p.y = m->list->p.y;
    if (m->cell[m->list->p.x][m->list->p.y].st >= 4)
        return;
    if (rdm == 1 && m->list->p.x + 1 < m->line + 2 && m->cell[m->list->p.x \
    + 1][m->list->p.y].type != '0' && m->cell[m->list->p.x + 1][m->list->p.y \
    ].visit == false && m->cell[m->list->p.x + 2][m->list->p.y].visit == false \
    && tcheck_path(m, (pos_t){p.x + 1, p.y})) {
        ++p.x;
        m->cell[p.x][p.y].visit = true;
        m->cell[p.x][p.y].type = '*';
        list_push(&m->list, p);
        ++m->s_list;
    } else {
        rdm = 2;
        m->cell[m->list->p.x][m->list->p.y].st++;
        go_left(m, rdm);
    }
}

void go_top(maze_t *m, int rdm)
{
    pos_t p = {0, 0};

    if (m->cell[m->list->p.x][m->list->p.y].st >= 4)
        return ;
    p.x = m->list->p.x;
    p.y = m->list->p.y;
    if (rdm == 0 && m->list->p.y - 1 > 1 && m->cell[m->list->p.x - 1][m->list->\
    p.y].type != '0' && m->cell[m->list->p.x - 1][m->list->p.y].visit == false \
    && m->cell[m->list->p.x - 2][m->list->p.y].visit == false && tcheck_path \
    (m, (pos_t){p.x - 1, p.y})) {
        --p.x;
        m->cell[p.x][p.y].visit = true;
        m->cell[p.x][p.y].type = '*';
        list_push(&m->list, p);
        ++m->s_list;
    } else {
        rdm = 1;
        m->cell[m->list->p.x][m->list->p.y].st++;
        go_bottom(m, rdm);
    }
}