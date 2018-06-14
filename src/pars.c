/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Parsing
*/

#include <stdio.h>
#include <dirent.h>

int pars_command(int ac, char **av)
{
	DIR *dir = NULL;

	if (ac <= 1 || ac > 4)
		return (1);
	dir = opendir(av[1]);
	if (dir == NULL)
		return (1);
	else if (closedir(dir) == -1)
		return (1);
	else
		return (0);
}
