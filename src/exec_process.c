/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Exec process
*/

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include "tester.h"

char **create_path(char *bin)
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
	return (path);
}

int access_test(char **path)
{
	int a = 0;

	while (path[a]) {
		if (access(path[a], R_OK | X_OK) == 0)
			return (a);
		a++;
	}
	return (-1);
}

int child_process(save_s save, char *bin)
{
	char **path = create_path(bin);
	int a = access_test(path);
	char **new_args = make_args(bin, save.args);

	if (path == NULL || new_args == NULL || strcmp("cat", bin) == 0)
		return (0);
	if (a == -1) {
		kill(getpid(), 15);
		return (1);
	} else if (execve(path[a], new_args, NULL) == -1)
		return (1);
	return (0);
}

pid_t create_process(void)
{
	pid_t pid = 0;

	do {
		pid = fork();
	} while (pid == -1 && errno == EAGAIN);
	return (pid);
}

int exec_process(char *bin, save_s save)
{
	pid_t pid = 0;

	pid = create_process();
	if (pid == 0)
		child_process(save, bin);
	else
		wait(NULL);
	return (0);
}
