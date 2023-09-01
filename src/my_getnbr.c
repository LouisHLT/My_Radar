/*
** EPITECH PROJECT, 2022
** getnbr
** File description:
** getnbr
*/

int get_back(char const *str, int i, int my_stop)
{
    if (str[i + 1] < '0' || str[i + 1] > '9') {
        my_stop = 1;
    }
    return (my_stop);
}

int my_getnbr(char const *str)
{
    int my_stop = 0;
    long number = 0;
    int neg = 1;

    for (int i = 0; str[i] != '\0' && my_stop == 0; i++) {
        if (str[i] == '-') {
            neg *= (-1);
        }
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - 48);
            my_stop = get_back(str, i, my_stop);
        }
        number *= neg;
    }
    return (number * neg);
}
