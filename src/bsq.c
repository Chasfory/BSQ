/*
** EPITECH PROJECT, 2021
** fs_printf_first_line.c
** File description:
** step 5
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"
#include "stdlib.h"
#include "my.h"
#include "bsbsq.h"

int square_demineur(int **str, int len, int column)
{
    int a = 0;
    int b = 0;
    int c = 0;

    if (column == 0 || len == 0)
        return (1);
    a = str[len - 1][column - 1];
    b = str[len - 1][column];
    c = str[len][column - 1];
    if (a <= b && a <= c) {
        a++;
        return (a);
    }
    if (b <= a && b <= c) {
        b++;
        return (b);
    }
    c++;
    return (c);
}

char **bsq_demineur(char **square, int x, int y, int nb)
{
    int i = x;

    for (int len = 0; len < nb; len++) {
        for (int spe = 0; spe < nb; spe++) {
            square[y][x] = 'x';
            x--;
        }
        x = i;
        y--;
    }
    return (square);
}

char **big_square(int **str, int compt, char **square, int k)
{
    int nb = 0;
    int x = 0;
    int y = 0;

    for (int len = 0; len < compt; len++) {
        for (int column = 0; column < k; column++) {
            if (str[len][column] == 1)
                str[len][column] = square_demineur(str, len, column);
            if (str[len][column] == 0)
                str[len][column] = 0;
            if (nb < str[len][column]) {
                nb = str[len][column];
                x = column;
                y = len;
            }
        }
    }
    square = bsq_demineur(square, x, y, nb);
    return (square);
}

char **demineur_inverse(char **str, char const *stl)
{
    int compt = my_compt_len(stl);
    int **stock = malloc(sizeof(int *) * (compt + 1));
    int k = my_strlen_bis(str[0]);

    for (int j = 0; j < compt; j++) {
        stock[j] = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            if (str[j][i] == '.')
                stock[j][i] = 1;
            else if (str[j][i] == 'o')
                stock[j][i] = 0;
        }
    }
    stock[compt] = NULL;
    str = big_square(stock, compt, str, k);
    for (int i = 0; stock[i] != NULL; i++)
        free(stock[i]);
    free(stock);
    return (str);
}

int bsq(char const *filepath)
{
    struct stat stats;
    int fd = open(filepath, O_RDONLY);
    ssize_t stl;
    char **str;
    char *buffer = NULL;

    if (stat(filepath, &stats) == -1)
        return (84);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (fd == -1 || stats.st_size == 0)
        return (84);
    stl = read(fd, buffer, stats.st_size);
    if (stl == -1)
        return (84);
    buffer[stats.st_size] = '\0';
    if (fonct_error(buffer) == 84)
        return (84);
    str = my_str_to_word_array_bsq(buffer);
    display_free(str, buffer);
    return (0);
}