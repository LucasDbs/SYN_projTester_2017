/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Other functions
*/

#include <stdio.h>

int delete_ext(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] == '.') {
			str[i] = '\0';
			return (0);
		}
		i++;
	}
	return (0);
}

int total_size(char **tab)
{
	int i = 0;
	int j = 0;
	int nb = 0;

	while (tab[i]) {
		while (tab[i][j]) {
			nb++;
			j++;
		}
		nb++;
		j = 0;
		i++;
	}
	return (nb);
}