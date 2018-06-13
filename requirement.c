/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** requirement.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t create_process(void)
{
	pid_t pid = 0;

	do {
		pid = fork();
	} while (pid == -1);
	return (pid);
}

void my_ps_synthesis(void)
{
	pid_t pid = create_process();
	char *arg[2] = {"ps", NULL};

	if (pid == 0)
		execve("/bin/ps", arg, NULL);
	else {
		wait(NULL);
	}
}
