/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** imperfect_maze
*/

#include "../include/generator.h"

inline int tcheck_imperfect(const maze_t *m, const int x_rdm, const int y_rdm)
{
    int testeur = 0;

    if (m->cell[x_rdm + 1][y_rdm].type == '*')
        testeur++;
    if (m->cell[x_rdm - 1][y_rdm].type == '*')
        testeur++;
    if (m->cell[x_rdm][y_rdm + 1].type == '*')
        testeur++;
    if (m->cell[x_rdm][y_rdm - 1].type == '*')
        testeur++;
    return (testeur);
}

void create_imperfect(maze_t *m, int state)
{
    int x = 2;
    int y = 2;
    int x_max = m->line + 1;
    int y_max = m->cols + 1;
    int x_rdm = rand() % x_max + x;
    int y_rdm = rand() % y_max + y;
    int tcheck = tcheck_imperfect(m, x_rdm, y_rdm);

    srand(rdtsc());
    if (state >= ((m->cols * m->line) / 6))
        return ;
    if ((m->cell[x_rdm][y_rdm].type == 'X') && (tcheck >= 1 && tcheck <= 2)) {
        ++state;
        m->cell[x_rdm][y_rdm].type = '*';
        m->cell[x_rdm][y_rdm].visit = true;
        create_imperfect(m, state);
    } else {
        ++state;
        create_imperfect(m, state);
    }
}