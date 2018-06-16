/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Found binary
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "tester.h"

extern char **environ;

int rework_first(char **tab, char c)
{
	int i = 0;
	int a = 0;

	if (tab == NULL)
		return (0);
	while (tab[0][i] != c)
		i++;
	i++;
	while (tab[0][i])
		tab[0][a++] = tab[0][i++];
	tab[0][a] = '\0';
	return (0);
}

int check_acces(char **path)
{
	int i = 0;

	while (path[i]) {
		if (access(path[i], F_OK | X_OK) == 0) {
			free_tab(path);
			return (0);
		}
		i++;
	}
	dprintf(2, "Error: Binary not found.\n");
	free_tab(path);
	return (1);
}

char **fnd_path(void)
{
	int i = 0;

	while (environ[i]) {
		if (strncmp("PATH=", environ[i], 5) == 0)
			return (str_to_word_tab(environ[i], ':'));
		i++;
	}
	return (NULL);
}

int check_path(char *bin)
{
	int i = 0;
	char **path = fnd_path();

	rework_first(path, '=');
	while (path[i]) {
		path[i] = realloc(path[i], (strlen(path[i]) + strlen(bin) + 2));
		path[i] = strcat(path[i], "/");
		path[i] = strcat(path[i], bin);
		i++;
	}
	return (check_acces(path));
}

int fnd_bin(char *bin)
{
	DIR *dir = opendir(".");
	struct dirent *ep;
	char **tmp = NULL;

	while ((ep = readdir(dir)) != NULL) {
		if (strcmp(bin, ep->d_name) == 0) {
			closedir(dir);
			tmp = malloc(sizeof(char *) * 2);
			tmp[0] = strdup(bin);
			tmp[1] = NULL;
			return (check_acces(tmp));
		}
	}
	closedir(dir);
	return (check_path(bin));
}
