/*
** EPITECH PROJECT, 2021
** my_str_to_word_array_bsq.c
** File description:
** bsq
*/

#include <stdio.h>
#include <stdlib.h>
#include "bsbsq.h"

int my_strlen_to_len(char const *str)
{
    int compt = 0;
    int i = 0;

    for (; str[i] != '\n'; i++);
    i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            compt++;
    }
    return (compt + 1);
}

char **my_str_to_word_array_bsq(char const *str)
{
    int compt = my_strlen_to_len(str);
    char **stock = malloc(sizeof(char *) * (compt + 1));
    int k = my_strlen(str);
    int i = 0;
    int j = 0;

    for (; str[j] != '\n'; j++);
    j++;
    for (; i < compt; i++)
    {
        stock[i] = malloc(sizeof(char) * (k + 1));
        stock[i] = my_strncpy(stock[i], &str[j], k);
        stock[i][k] = '\0';
        j += k;
        if (str[j] == '\n')
            j++;
    }
    stock[i - 1] = NULL;
    return (demineur_inverse(stock, str));
}