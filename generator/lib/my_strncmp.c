/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n == 0) {
        return (s1[0] - s2[0]);
    }
    if (s1[0] == 0) {
        return (0 - s2[0]);
    }
    if (s2[0] == 0) {
        return (s1[0] - 0);
    }
    if (s1[0] == s2[0]) {
        n--;
        return (my_strncmp(s1 + 1, s2 + 1, n));
    }
    return (s1[0] - s2[0]);
}