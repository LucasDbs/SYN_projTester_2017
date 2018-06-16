/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Other functions
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int tab_size(char **tab)
{
	int i = 0;

	while (tab[i])
		i++;
	return (i);
}

char **make_args(char *bin, char **args)
{
	char **tab = malloc(sizeof(char *) * (tab_size(args) + 2));
	int i = 0;
	int a = 1;

	tab[0] = strdup(bin);
	while (args[i])
		tab[a++] = strdup(args[i++]);
	tab[a] = NULL;
	return (tab);
}

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
