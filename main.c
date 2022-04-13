/*
** EPITECH PROJECT, 2021
** fs_printf_first_line.c
** File description:
** step 5
*/

#include "bsbsq.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (bsq(av[1]));
}