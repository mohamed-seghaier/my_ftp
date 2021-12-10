/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** flags pour le printf
*/

#include "../include/my.h"

void	flag_d(va_list ap)
{
	my_putnbr(va_arg(ap, int));
}

void	flag_s(va_list ap)
{
	my_putstr(va_arg(ap, char *));
}

void	flag_c(va_list ap)
{
	my_putchar(va_arg(ap, int));
}

void	my_sputchar(char c)
{
	write(1, &c, 1);
}

void	my_sputstr(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1)
		my_sputchar(str[i]);
}
