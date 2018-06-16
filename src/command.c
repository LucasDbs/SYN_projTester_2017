/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Command
*/

#include <stdlib.h>
#include <ftw.h>
#include <stdio.h>
#include "tester.h"

int search_function(char const *fpath, const struct stat *sb, int typeflag)
{
	(void)sb;
	FILE *file = fopen(".tmp.txt", "a+");

	if (file == NULL)
		return (0);
	fprintf(file, "%s\n", fpath);
	fprintf(file, "%d\n", typeflag);
	fclose(file);
	return (0);
}

int check_command(int ac, char **av)
{
	save_s *save = NULL;

	ftw(av[1], search_function, 20);
	save = create_save();
	qsort(save, size_struct(save), sizeof(*save), sort_struct);
	if (ac == 2) {
		tree_print(save);
	} else if (ac == 3) {
		if (fnd_bin(av[2]) == 1) {
			free_struct(save);
			remove(".tmp.txt");
			return (1);
		} else
			check_args(save, av[2]);
	}
	remove(".tmp.txt");
	free_struct(save);
	return (0);
}
