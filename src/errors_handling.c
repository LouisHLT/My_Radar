/*
** EPITECH PROJECT, 2022
** TEK1_22-23
** File description:
** errors_handling.c
*/

#include "my.h"

void help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr(" path_to_script     The path to the script file\n\n");
    my_putstr("OPTION\n");
    my_putstr(" -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  'L'  key      enable/disable hitboxes and areas\n");
    my_putstr("  'S'  key      enable/disable sprites\n");
}

int error_handling(int ac, char **av)
{
    int res = 0;
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            help();
            res = 0;
        }
    return res;
}
