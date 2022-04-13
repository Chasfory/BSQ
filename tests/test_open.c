/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsbsq.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(bsq, test_open_1, .init = redirect_all_std)
{
    bsq("tests/maps_open_test");
    cr_assert_stdout_eq_str("x");
}

Test(bsq, test_open_simple_caractere, .init = redirect_all_std)
{
    bsq("tests/intermediate_map_one_filled_box");
    cr_assert_stdout_eq_str("o");
}

Test(bsq, error_test_one, .init = redirect_all_std)
{
    int error = 0;

    error = bsq("tests/maps_error_1");
    cr_assert_eq(84, error);
}

Test(bsq, error_test_two, .init = redirect_all_std)
{
    int error = 0;

    error = bsq("tests/maps_error_2");
    cr_assert_eq(84, error);
}

Test(bsq, font_simple_b, .init = redirect_all_std)
{
    int error = 0;

    error = bsq("tests/empty_maps");
    cr_assert_eq(84, error);
}

Test(my_strlen_to_len, fonct_simple_bis, .init = redirect_all_std)
{
    int a = 0;

    a = my_strlen_to_len("to\npapa\n");
    cr_assert_eq(2, a);
}

Test(fonct_error, fonct_simple_four, .init = redirect_all_std)
{
    int a = 0;

    a = fonct_error("1\n.oo.....o...o...ooo...o.o....oo..oo..o...\n...o.....oo...oo.oo.......o.o.oo.o.......\n");
    cr_assert_eq(84, a);
}

Test(fonct_error, fonct_simple_fifith, .init = redirect_all_std)
{
    int a = 0;

    a = fonct_error("1\n.oo.....o...o...ooo...o.o....oo..oo..o...\n");
    cr_assert_eq(0, a);
}

Test(fonct_error, fonct_simple_six, .init = redirect_all_std)
{
    int a = 0;

    a = fonct_error("2\n.oo.....o...o...ooo...o.o....oo..oo..o...\n");
    cr_assert_eq(84, a);
}

Test(my_strlen_to_error, fonct_simple_seven, .init = redirect_all_std)
{
    int a = 0;

    a = my_strlen_to_error("1\n.oo.....o...o...ooo...o.o....oo..oo..o...\n");
    cr_assert_eq(1, a);
}

Test(my_compt_len, fonct_simple_eight, .init = redirect_all_std)
{
    int a = 0;

    a = my_compt_len("1\n.oo.....o...o...ooo...o.o....oo..oo..o...\n");
    cr_assert_eq(1, a);
}

Test(my_strlen_bis, fonct_simple_nine, .init = redirect_all_std)
{
    int a = 0;

    a = my_strlen_bis("o...ooo");
    cr_assert_eq(7, a);
}