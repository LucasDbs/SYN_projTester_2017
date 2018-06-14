/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int test_function(char const *fpath, const struct stat *sb, int typeflag)
{
	(void)sb;
	FILE *file = fopen(".tmp.txt", "a+");

	fprintf(file, "%s\n", fpath);
	fprintf(file, "%d\n", typeflag);
	fclose(file);
	return (0);
}

int main(int ac, char **av)
{
	save_s *save = NULL;

	if (pars_command(ac, av) == 1)
		return (84);
	else {
		ftw(av[1], test_function, 20);
		save = create_save();
		qsort(save, size_struct(save), sizeof(*save), sort_struct);
		struct_print(save);
		free_struct(save);
		remove(".tmp.txt");
	}
	return (0);
}
