/*
** EPITECH PROJECT, 2019
** my_str_to_array
** File description:
** .c
*/

#include "../include/my.h"

static int my_check(char *str, char c)
{
    int i = 0;
    for (i = 0; str[i]; i += 1) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

static int count_line(char *str, char *sep)
{
    int i = 0;
    int val = 0;

    for(int i = 0; str[i];) {
        while (str[i] && my_check(sep, str[i++]) != -1);
        val++;
        while (str[i] && my_check(sep, str[i++]) == -1);
    }
    return (val);
}

static char *my_cut_str(char *str, char *sep)
{
    int i = -1;

    while (str[++i]) {
        if (my_check(sep, str[i]) != -1)
            str[i] = 0;
    }
    return (str);
}

char **my_str_to_array(char *str, char *sep)
{
    int j = 0;
    int t = -1;
    int i = count_line(str, sep);
    char **tab = malloc(sizeof(char *) * (count_line(str, sep) + 1));

    if (str == NULL || tab == NULL)
        return (NULL);
    str = my_cut_str(str, sep);
    while (++t < i){
        tab[t] = &str[j];
        while (str[j++]);
    }
    tab[t] = NULL;
    return (tab);
}
