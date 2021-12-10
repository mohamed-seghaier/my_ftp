/*
** EPITECH PROJECT, 2018
** my_printers.c
** File description:
** toute fonction servant à print
*/

#include "../include/my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i;

	for (i = 0; str[i]; i++)
		my_putchar(str[i]);
}

void	my_putnbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		my_putnbr(nb * -1);
	}
	else if (nb > 9) {
		my_putnbr(nb / 10);
		my_putnbr(nb % 10);
	}
	else
		my_putchar(nb + 48);
}
