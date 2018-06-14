/*
** EPITECH PROJECT, 2018
** Duboisse Lucas
** File description:
** Tester.h
*/

#ifndef TESTER_H_
#define TESTER_H_

typedef struct save_s
{
	int type;
	char *name; 
} save_s;

int sort_struct(void const *, void const *);
int pars_command(int, char **);
save_s *create_save(void);
int size_struct(save_s *);
int free_tab(char **);
int struct_print(save_s *);
int free_struct(save_s *);
int tree_print(save_s *);
int check_command(int, char **);
int fnd_bin(char *);
char **str_to_word_tab(char const *, char);

#endif