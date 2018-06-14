/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Print functions
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tester.h"

char *create_hyphen(int nb)
{
	char *res = malloc(sizeof(char) * ((5 * nb) + 1));
	int i = 0;

	while (i < (nb * 5))
		res[i++] = '-';
	res[i] = '\0';
	return (res);
}

char *make_hyphen(char *str, int slash)
{
	int i = 0;
	int nb = 0;

	while (str[i] == '.' && str[i] != '\0')
		i++;
	i++;
	while (str[i] != '\0') {
		if (str[i] == '/')
			nb++;
		i++;
	}
	return (create_hyphen(nb - slash));
}

char *rework_path(char *str)
{
	int i = strlen(str);
	int a = 0;
	char *res = malloc(sizeof(char) * (i + 1));

	while (str[i] != '/' && i != 0)
		i--;
	if (str[i] == '/')
		i++;
	while (str[i])
		res[a++] = str[i++];
	res[a] = '\0';
	return (res);
}

int fnd_slash(char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i]) {
		if (str[i] == '/' && str[i - 1] != '.')
			nb++;
		i++;
	}
	return (nb);
}

int special_print(save_s *save)
{
	int i = 0;
	char *path = NULL;
	char *hyphen = NULL;
	int nb_slash = fnd_slash(save[0].name);

	while (save[i].name) {
		path = rework_path(save[i].name);
		hyphen = make_hyphen(save[i].name, nb_slash);
		printf("%s%s\n", hyphen, path);
		free(path);
		free(hyphen);
		i++;
	}
	return (0);
}