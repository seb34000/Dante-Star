/*
** EPITECH PROJECT, 2021
** B-CPE-200-MPL-2-1-dante-sebastien.phelip
** File description:
** list
*/

#include "../include/generator.h"

list_t *init_list(void)
{
    list_t *l = malloc(sizeof(list_t));

    l->p.x = 2;
    l->p.y = 2;
    l->n = NULL;
    return (l);
}

void list_push(list_t **list, pos_t p)
{
    list_t *new;

    if (list == NULL)
        return ;
    new = malloc(sizeof(list_t));
    new->p.x = p.x;
    new->p.y = p.y;
    new->n = (*list);
    (*list) = new;
}

pos_t list_pop(list_t **list)
{
    pos_t p = {-1, -1};
    list_t *save = NULL;

    if (list == NULL)
        return (p);
    p = (*list)->p;
    save = (*list);
    (*list) = NULL;
    (*list) = save->n;
    free (save);
    return (p);
}

size_t list_size(list_t *list)
{
    list_t *current = list;
    size_t size = 0;

    if (current == NULL) {
        return (size);
    } else {
        while (current != NULL) {
            current = (*current).n;
            size += 1;
        }
    }
    return (size);
}