/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** rdm_nbr
*/

unsigned long long rdtsc(void)
{
    unsigned int lo;
    unsigned int hi;

    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}