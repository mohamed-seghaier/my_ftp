/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** fonction en remplacement du printf
*/

#include "../include/my.h"

void	my_printf(char *str, ...)
{
	int	i = 0;
	va_list	ap;

	va_start(ap, 0);
	for (i = 0; str[i];) {
		if (str[i] == '%' && (checkflag(str[i + 1]) != -1)) {
			my_ptab(checkflag(str[i + 1]), ap);
			i += 2;
		}
		else {
			my_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
}

int	checkflag(char c)
{
	int	i = 0;
	char	str[4] = "dsc";

	for (i = 0; str[i]; i++)
		if (str[i] == c)
			return (i);
	return (-1);
}

void	my_ptab(int i, va_list ap)
{
	void	(*tab[4])(va_list);

	tab[0] = &flag_d;
	tab[1] = &flag_s;
	tab[2] = &flag_c;
	tab[3] = NULL;
	(*tab[i])(ap);
}
