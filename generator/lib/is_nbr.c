/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** is_nbr
*/

#include <stdbool.h>

bool is_number(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}