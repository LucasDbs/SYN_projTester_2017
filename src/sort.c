/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Main function
*/

#include <string.h>
#include "tester.h"

int sort_struct(void const *a, void const *b)
{
	save_s const *pa = a;
	save_s const *pb = b;

	return (strcmp(pa->name, pb->name));
}
