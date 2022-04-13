/*
** EPITECH PROJECT, 2021
** bsq.h
** File description:
** semestre1
*/

#ifndef _BSQ_H_
#define _BSQ_H_

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int my_strlen_bis(char const *str);
int bsq(char const *filepath);
char **demineur_inverse(char **str, char const *stl);
int square_demineur(int **str, int len, int column);
char **bsq_demineur(char **square, int x, int y, int nb);
char **big_square(int **str, int compt, char **square, int k);
int my_compt_len(char const *str);
int display_free(char **str, char *buffer);
int fonct_error(char *buffer);
char **my_str_to_word_array_bsq(char const *str);
int my_strlen_to_len(char const *str);

#endif
