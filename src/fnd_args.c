/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Found arguments
*/

#include <ftw.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tester.h"

char **add_args(char *path)
{
	FILE *file = fopen(path, "r");
	char *res = NULL;
	size_t size;
	char **tab = NULL;
	int end = 0;

	while ((end = getline(&res, &size, file)) != EOF) {
		if (res[end - 1] == '\n')
			res[end - 1] = '\0';
		if (strncmp("ARGS:", res, 5) == 0) {
			tab = str_to_word_tab(res, ' ');
			fclose(file);
			free(res);
			return (tab);
		}
	}
	free(res);
	fclose(file);
	return (NULL);
}

int check_args(save_s *save, char *av)
{
	int i = 0;

	while (save[i].name) {
		if (save[i].type == FTW_F) {
			save[i].args = add_args(save[i].name);
			rework_first(save[i].args, ':');
			exec_test(save[i], save[0].name, av);
		}
		i++;
	}
	return (0);
}
