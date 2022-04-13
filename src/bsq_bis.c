/*
** EPITECH PROJECT, 2021
** bsq_bis.c
** File description:
** bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"
#include "stdlib.h"
#include "my.h"
#include "bsbsq.h"

int my_strlen_bis(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int my_compt_len(char const *str)
{
    int compt = 0;
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    i++;
    for (;str[i] != '\0'; i++) {
        if (str[i] == '\n')
            compt++;
    }
    return (compt);
}

int my_strlen_to_error(char const *str)
{
    int compt = 0;
    int i = 0;

    for (; str[i] != '\n'; i++);
    i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            compt++;
    }
    return (compt);
}

int fonct_error(char *buffer)
{
    int nb = 0;
    int k = my_strlen(buffer);
    int i = 0;

    for (; buffer[i] <= '9' && buffer[i] >= '0'; i++) {
        nb += (buffer[i] - '0');
        if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9')
            nb *= 10;
    }
    if (my_strlen_to_error(buffer) != nb)
        return (84);
    i++;
    for (int compt = 0; buffer[i] != '\0'; i++) {
        for (compt = 0; buffer[i] != '\n'; i++) {
            compt++;
        }
        if (compt != k)
            return (84);
    }
    return (0);
}

int display_free(char **str, char *buffer)
{
    for (int i = 0; str[i] != NULL; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
    }
    free(buffer);
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
    return (0);
}