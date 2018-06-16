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

int add_args(save_s *save)
{
	FILE *file = fopen(save->name, "r");
	char *res = NULL;
	size_t size;
	int end = 0;

	if (file == NULL)
		return (84);
	while ((end = getline(&res, &size, file)) != EOF) {
		if (res[end - 1] == '\n')
			res[end - 1] = '\0';
		if (strncmp("ARGS:", res, 5) == 0)
			save->args = str_to_word_tab(res, ' ');
		else if (strncmp("INPUT:", res, 6) == 0)
			save->input = strdup(res);
	}
	free(res);
	fclose(file);
	return (0);
}

int check_args(save_s *save, char *av)
{
	int i = 0;

	while (save[i].name) {
		if (save[i].type == FTW_F) {
			add_args(&save[i]);
			rework_first(save[i].args, ':');
			exec_test(save[i], save[0].name, av);
		}
		i++;
	}
	return (0);
}
