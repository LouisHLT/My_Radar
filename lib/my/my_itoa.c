/*
** EPITECH PROJECT, 2022
** RADAR
** File description:
** my_itoa.c
*/

#include "my.h"

char *my_itoa(int nb)
{
    int tmp = nb;
    int length = 1;
    char *res;
    while ((tmp > 10) || (tmp < (-10))) {
        tmp = tmp / 10;
        length++;
    }
    res = malloc(sizeof(char) * (length + 1));
    res[length] = '\0';
    for (int i = length - 1; i >= 0; i--) {
        res[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    return res;
}
