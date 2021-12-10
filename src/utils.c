/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** oui
*/

#include "../include/my.h"

int	strcompar(char *str, char *ing)
{
	int	i = 0;
	int	len = my_strlen(ing);
	int	cmp = 0;

	for (i = 0; str[i] && ing[i]; i += 1)
		cmp += (str[i] == ing[i] ? 1 : 0);
	return ((len == cmp ? (1) : 0));
}

char	*my_supestrcpy(char *str)
{
	char	*dest;
	int	i = 0;
	int	idx = 0;
	int	len = my_strlen(str);

	if ((dest = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	for (i = 0; str[idx]; idx+= 1, i += 1)
		dest[i] = str[idx];
	dest[i] = 0;
	return (dest);
}

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i += 1);
    return (i);
}