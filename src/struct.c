/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Create struct
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tester.h"

int struct_print(save_s *tab)
{
	for (int i = 0; tab[i].name; i++) {
		printf("tab[%d]->name = %s\n", i, tab[i].name);
		printf("tab[%d]->type = %d\n", i, tab[i].type);
	}
	return (0);
}

int size_struct(save_s *tab)
{
	int i = 0;

	while (tab[i].name)
		i++;
	return (i);
}

int size_file(FILE *file)
{
	size_t size;
	char *res = NULL;
	int nb = 0;

	while (getline(&res, &size, file) != -1)
		nb++;
	free(res);
	rewind(file);
	return (nb / 2);
}

int add_to_struct(save_s *save, char *res, int *next, int *a)
{
	if ((*next) == 2) {
		(*a)++;
		(*next) = 0;
	}
	if (res[0] >= '0' && res[0] <= '1')
		save[*a].type = atoi(res);
	else
		save[*a].name = strdup(res);
	return (0);
}

save_s *create_save(void)
{
	FILE *file = fopen(".tmp.txt", "r");
	save_s *save = NULL;
	int a = 0;
	size_t size;
	char *res = NULL;
	int next = 0;
	int end = 0;

	if (file == NULL)
		return (NULL);
	save = malloc(sizeof(save_s) * (size_file(file) + 1));
	while ((end = getline(&res, &size, file)) != -1) {
		res[end - 1] = '\0';
		add_to_struct(save, res, &next, &a);
		next++;
	}
	fclose(file);
	free(res);
	save[a + 1].name = NULL;
	return (save);
}
