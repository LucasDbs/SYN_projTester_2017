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

	fprintf(file, "%s\n", fpath);
	fprintf(file, "%d\n", typeflag);
	fclose(file);
	return (0);
}

int check_command(int ac, char **av)
{
	save_s *save = NULL;

	if (ac == 2) {
		ftw(av[1], search_function, 20);
		save = create_save();
		qsort(save, size_struct(save), sizeof(*save), sort_struct);
		tree_print(save);
		free_struct(save);
		remove(".tmp.txt");
	} else if (ac == 3)
		return (fnd_bin(av[2]));
	return (0);
}