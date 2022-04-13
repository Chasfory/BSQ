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
#define RESET_ALL "\x1b[0m"
#define PC_BOLD "\x1b[1m"
#define PC_ITALIC "\x1b[3m"
#define UNDER_LINE "\x1b[4m"
#define UNDERLINE   "\x1b[21m"
#define FT_GREY "\x1b[2m"
#define FT_BLACK   "\x1b[30m"
#define FT_RED  "\x1b[31m"
#define FT_GREEN   "\x1b[32m"
#define FT_YELLOW  "\x1b[33m"
#define FT_BLUE "\x1b[34m"
#define FT_MAGENTA "\x1b[35m"
#define FT_CYAN "\x1b[36m"

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
