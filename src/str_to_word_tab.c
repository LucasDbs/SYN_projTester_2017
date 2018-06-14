/*
** EPITECH PROJECT, 2018
** Lucas Duboisse
** File description:
** str_to_word_array
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int start(char const *str, char c)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] == c)
		i++;
	return (i);
}

static int check_size(char const *str, char c)
{
	int nb = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		if (str[i] == c && (i == 0 || str[i - 1] != c))
			nb++;
		i++;
	}
	if (str[0] == c)
		nb--;
	if (str[strlen(str) - 1] == c)
		nb--;
	nb++;
	return (nb);
}

static int length(char const *str, int *cnt, char c)
{
	int size = 0;

	while (str[*cnt] == c)
		(*cnt)++;
	while (str[*cnt] != '\0' && str[*cnt] != c) {
		(*cnt)++;
		size++;
	}
	return (size);
}

char **str_to_word_tab(char const *str, char s)
{
	int size = check_size(str, s);
	char **array = malloc(sizeof(char *) * (size + 1));
	int c = start(str, s);
	int a = 0;

	if (array == NULL || str == NULL)
		return (NULL);
	for (int i = 0, cnt = 0; i != size; i++)
		array[i] = malloc(sizeof(char) * (length(str, &cnt, s) + 1));
	for (int cnt = 0; cnt != size; cnt++) {
		for (a = 0; str[c] != s && str[c] != '\0'; a++, c++)
			array[cnt][a] = str[c];
		array[cnt][a] = '\0';
		while (str[c] == s)
			c++;
	}
	array[size] = NULL;
	return (array);
}
