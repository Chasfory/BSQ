/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task
*/

#include <unistd.h>

int my_strlen_spe(char const *str)
{
    int compt = 0;

    for (; str[compt] != '\0'; compt++);
    return (compt);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen_spe(str));
}