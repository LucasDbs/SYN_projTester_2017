/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main(int ac, char **av)
{
	if (pars_command(ac, av) == 1)
		return (84);
	else if (check_command(ac, av) == 1)
		return (84);
	return (0);
}
