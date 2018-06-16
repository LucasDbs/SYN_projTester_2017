/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Args print
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tester.h"

char *delete_principal_path(char *name, char *principal)
{
	char *new = malloc(sizeof(char) * (strlen(name) + 1));
	int i = 0;
	int a = 0;

	if (new == NULL)
		return (NULL);
	while (name[i] == principal[i])
		i++;
	i++;
	while (name[i])
		new[a++] = name[i++];
	new[a] = '\0';
	return (new);
}

char *add_bracket(char *str)
{
	char *new = malloc(sizeof(char) * (strlen(str) + 3));
	int i = 0;
	int a = 0;

	new[a++] = '[';
	while (str[i])
		new[a++] = str[i++];
	new[a++] = ']';
	new[a] = '\0';
	free(str);
	return (new);
}

char **create_brackets(char *path)
{
	char **tab = str_to_word_tab(path, '/');
	int i = 0;

	while (tab[i + 1]) {
		tab[i] = add_bracket(tab[i]);
		i++;
	}
	delete_ext(tab[i]);
	return (tab);
}

char *args_line(char **tab)
{
	char *new = NULL;
	int i = 0;
	int j = 0;
	int a = 0;

	if (tab == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (total_size(tab) + 1));
	while (tab[i]) {
		while (tab[i][j])
			new[a++] = tab[i][j++];
		new[a++] = ' ';
		j = 0;
		i++;
	}
	new[a] = '\0';
	return (new);
}

int exec_test(save_s save, char *name, char *bin)
{
	char *new = delete_principal_path(save.name, name);
	char **path = create_brackets(new);
	int i = 0;

	if (save.args != NULL) {
		while (path[i + 1]) {
			dprintf(1, "%s ", path[i]);
			i++;
		}
		dprintf(1, "%s: ", path[i]);
		exec_process(bin, save);
	}
	free(new);
	free_tab(path);
	return (0);
}
