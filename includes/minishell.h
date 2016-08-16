/*
** minishell.h for header minishell in /home/vautri_b/Projets/Projets_S2/SystemeUnix/PSU_2015_minishell2
**
** Made by Bertrand Vautrin
** Login   <vautri_b@epitech.net>
**
** Started on  Wed Mar 23 09:59:31 2016 Bertrand Vautrin
** Last update Thu Jun 16 23:50:43 2016 Florian Vincent
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "macro.h"
#include "echo.h"

typedef struct	s_tree
{
  char		*data;
  struct s_tree	*right;
  struct s_tree	*left;
}		t_tree;

typedef struct		s_alias_info
{
  char			*alias_name;
  char			**alias;
}			t_alias_info;

typedef struct		s_alias_list
{
  t_alias_info		*data;
  struct s_alias_list	*next;
  struct s_alias_list	*prev;
}			t_alias_list;

typedef struct		s_histo
{
  char			*entry;
  struct s_histo	*prec;
  struct s_histo	*suiv;
}			t_histo;

typedef struct	s_env
{
  t_alias_list	*alias_root;
  t_histo	*histo;
  t_histo	*curr;
  int		pipe;
  int		pipe_value;
  char		*term;
  char		*stop;
  char		*input[NB_CAPABILITY];
  char		*(*fptr[NB_CAPABILITY])(int *idx,
					char *line,
					struct s_env *env);
  char		*up;
  char		*right;
  char		*left;
  int		width;
  int		p_size;
  char		**tabi;
  int		exit_statu;
  int		exit_call;
}		t_env;

typedef struct		s_list
{
  char			data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef int(*t_builtfc)(char **, t_env *);

typedef int(*t_tree_check)(t_tree *, char **);

typedef int(*t_tree_exect)(t_tree *,
			   t_env *,
			   char **);

/*
** Alias
*/

t_alias_list		*create_alias(void);
int			my_add_alias(t_alias_list *root,
				     t_alias_info	*ai);
void			my_free_alias(t_alias_list *root);
void			my_delete_alias(t_alias_list *root,
					t_alias_list *current);

/*
** List
*/

t_list		*create_list(void);
int		my_add_to_end_list(t_list *root,
				   char data);
void		my_free_list(t_list *root);

/*
** History List
*/

t_histo		*create_my_list(void);
void		add_to_list(t_histo *element,
			    char *str);
void		free_my_list(t_histo *root);
void		delete_my_list(t_histo *current);

/*
** Basic functions
*/

int		my_prompt(void);
char		**my_globing(char **av);
char		**my_wordtab_cat(char **w1, char **w2, int free_tab);
int		my_show_wordtab(const char **wordtab);
int		my_alphanumeric(char *str);
int		my_strtablen(char **tabi);
int		my_strlen(const char *str);
int		my_strcmp(const char *s1, const char *s2);
int		my_get_nbr(const char *str);
int		my_strstr(char *str, char *find);
int		my_puterr(const char *str);
char		*my_strcat(const char *s1, const char *s2);
char		*my_strdup(const char *str);
char		**my_strtabdup(char **tabi);
char		**my_str_to_wordtab(char *str, char *separators, int flag);
int		my_printf(const char *, ...);
void		my_putchar(char c);
void		my_putnbr_base(int nbr, char *base);
void		my_exit(int value);

/*
** Updated basic Functions
*/

int		my_nstrlen(const char *str, int beg);
char		*my_nstrdup(const char *str, int beg);

/*
** Exect functions
*/

char		**add_options(char **av, t_env *env);
int		treat_status(int status);
int		my_cd(char *dest, t_env *env);
int		my_exect(char * const av[], t_env *env, const char *name);
int		my_builtins(char **av, t_env *env);
int		my_normal_exect_command(char *str, t_env *env, int flag);
int		globi(char *str);

/*
** Check Functions
*/

int		check_access(const char *filename);
int		check_command(char **av, char **path, char **tmp);
int		is_path(const char *str);
int		is_num(const char *str);
int		is_builtins(const char *str);
int		is_empty(char *str);

/*
** Env functions
*/

char		*my_getenv(const char *str, char **ev);
void		my_setenv(char *name, char *value, t_env *env);
int		my_unsetenv(char *str, t_env *env);

/*
** Builtins Functions
*/

int		built_env(char **av, t_env *env);
int		built_setenv(char **av, t_env *env);
int		built_unsetenv(char **av, t_env *env);
int		built_cd(char **av, t_env *env);
int		built_exit(char **av, t_env *env);
int		built_echo(char **av, t_env *env);
int		built_export(char **av, t_env *env);
int		built_alias(char **av, t_env *env);

/*
** Init Functions
*/

char		**init_path(char **env);
void		init_builtins(char **tabi);
void		init_builtins_fct(t_builtfc *tabi);
int		load_42shrc(t_env *env);

/*
** Tree Exect Functions
*/

int		and_exect_fct(t_tree *tree, t_env *env, char **sep);
int		or_exect_fct(t_tree *tree, t_env *env, char **sep);
int		double_right_red_exect_fct(t_tree *tree, t_env *env, char **sep);
int		right_red_exect_fct(t_tree *tree, t_env *env, char **sep);
int		double_left_red_exect_fct(t_tree *tree, t_env *env, char **sep);
int		left_red_exect_fct(t_tree *tree, t_env *env, char **sep);
int		suit_exect_fct(t_tree *tree, t_env *env, char **sep);
int		pipe_exect_fct(t_tree *tree, t_env *env, char **sep);

/*
** Tree Check Functions
*/

int		suit_check_fct(t_tree *tree, char **sep);
int		and_check_fct(t_tree *tree, char **sep);
int		or_check_fct(t_tree *tree, char **sep);
int		pipe_check_fct(t_tree *tree, char **sep);
int		double_right_red_check_fct(t_tree *tree, char **sep);
int		right_red_check_fct(t_tree *tree, char **sep);
int		double_left_red_check_fct(t_tree *tree, char **sep);
int		left_red_check_fct(t_tree *tree, char **sep);

void		free_tab(char **tabi);
void		my_putstrtab(char **tabi);
void		malloc_failed(void);
void		ctrl_c(int sig);
void		ctrl_c2(int sig);
int		is_separator(char c, const char *str);
int		my_tree_exect_command(char *str, t_env *env);

char		*get_next_line(const int fd);
char		*red_cut(char *str, char *sep, char *red);
char		*cut(char *str, char *separator, int flag);
t_tree		*build_tree(char *str, char **sep);
int		my_tree_exect(t_tree *tree, t_env *env, char **sep);
int		is_separator_in(char *str, char **sep);
int		is_separator2(char *str, char **sep);
void		reset_fd(int *fd);
int		check_tree(t_tree *tree, char **sep);
char		*find_path_command(char **av, char **path);
int		get_input(char *end);

void		*my_malloc(size_t);

/*
**
*/

t_list		*create_list(void);
int		my_add_to_end_list(t_list *root,
				   char data);
void		my_free_list(t_list *root);
int		set_termios(int i, t_env *env);
void		my_delete_list(t_list *current);
char		*my_strcat_input(char c, char *str);
int		my_istrcmp(const char *cmp, const char *new);
void		init_ptr(t_env *env);

char		*my_add_char(char *line, char c, int idx);
char		*my_back(int *idx, char *line, t_env *env);
char		*my_forward(int *idx, char *line, t_env *env);
char		*my_up(int *idx, char *line, t_env *env);
char		*my_down(int *idx, char *line, t_env *env);
char		*my_tab(int *idx, char *line, t_env *env);
char		*my_del(int *idx, char *line, t_env *env);
char		*getch_next(t_env *env);
int		reset_options(t_echo *echo_option);

/*
** History List
*/

t_histo		*create_my_list(void);
void		add_to_list(t_histo *element,
			    char *str);
void		free_my_list(t_histo *root);
void		delete_my_list(t_histo *current);
int		my_get_n_nbr(const char *str, int n);
void		change_word(t_env *env, char *line, int *idx);

#endif	/* ! MINISHELL_H_ */
