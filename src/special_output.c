/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** File output
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "tester.h"

int special_output(save_s save, char **path, char **av)
{
	int fd = open(av[3], O_CREAT | O_WRONLY | O_APPEND, 0664);
	int fd_tmp;
	int i = 0;

	if (fd == -1)
		return (0);
	fd_tmp = dup(1);
	dup2(fd, 1);
	if (save.args != NULL) {
		while (path[i + 1]) {
			dprintf(1, "%s ", path[i]);
			i++;
		}
		dprintf(1, "%s: ", path[i]);
		exec_process(av[2], save);
	}
	close(fd);
	dup2(fd_tmp, 1);
	free_tab(path);
	return (0);
}
