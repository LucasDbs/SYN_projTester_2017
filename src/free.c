/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Free functions
*/

#include <stdlib.h>
#include "tester.h"

int free_tab(char **tab)
{
	if (tab == NULL)
		return (0);
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
	return (0);	
}

int free_struct(save_s *tab)
{
	for (int i = 0; tab[i].name; i++) {
		free(tab[i].name);
		free_tab(tab[i].args);
	}
	free(tab);
	return (0);
}
