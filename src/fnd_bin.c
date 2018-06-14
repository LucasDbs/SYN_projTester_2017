/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Found binary
*/

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "tester.h"

int rework_first(char *str)
{
	int i = 0;
	int a = 0;

	while (str[i] != '=')
		i++;
	i++;
	while (str[i])
		str[a++] = str[i++];
	str[a] = '\0';
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

	rework_first(path[0]);
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
	char **tmp = malloc(sizeof(char *) * 2);

	while ((ep = readdir(dir)) != NULL) {
		if (strcmp(bin, ep->d_name) == 0) {
			closedir(dir);
			tmp[0] = strdup(bin);
			tmp[1] = NULL;
			return (check_acces(tmp));
		}
	}
	closedir(dir);
	return (check_path(bin));
}