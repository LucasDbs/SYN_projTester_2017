/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Free functions
*/

#include <stdlib.h>
#include "tester.h"

int free_struct(save_s *tab)
{
	for (int i = 0; tab[i].name; i++)
		free(tab[i].name);
	free(tab);
	return (0);
}
