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
	char **args;
	char *input;
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
int check_args(save_s *, char *);
int rework_first(char **, char);
int exec_test(save_s, char *, char *);
int delete_ext(char *);
int total_size(char **);
int exec_process(char *, save_s);
char **fnd_path(void);
void my_putstr(char *, int);
char **make_args(char *, char **);

#endif
