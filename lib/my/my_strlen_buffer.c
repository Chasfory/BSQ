/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** task
*/

#include <unistd.h>

int my_strlen_buffer(char const *str)
{
    int compt = 0;
    int len = 0;

    for (; str[len] != '\n'; len++) {
        compt++;
    }
    compt++;
    return (compt);
}