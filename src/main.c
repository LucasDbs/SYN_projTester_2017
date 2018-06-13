/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tester.h"

/*int free_struct(save_s * tab)
{
	for (int i = 0; tab[i].name; i++)
		free(tab[i].name);
	free(tab);
	return (0);
}

int struct_print(save_s * tab)
{
	for (int i = 0; tab[i].name; i++) {
		printf("tab[%d]->type = %d\n", i, tab[i].type);
		printf("tab[%d]->name = %s\n", i, tab[i].name);
	}
	return (0);
}

int size_struct(save_s * tab)
{
	int i = 0;

	while (tab[i].name)
		i++;
	printf("i = %d\n", i);
	return (i);
}*/

int test_function(char const *fpath, const struct stat *sb, int typeflag)
{
	(void)sb;
	FILE *file = fopen(".tmp.txt", "a+");

	fprintf(file, "%s\n", fpath);
	fprintf(file, "%d\n", typeflag);
	fclose(file);
	return (0);
}

//	remove(".tmp.txt");

int main(int ac, char **av)
{
	if (pars_command(ac, av) == 1)
		return (84);
	return (0);
}

//	ftw(av[1], test_function, 20);
