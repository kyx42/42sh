##
## Makefile for Makefile Minishell1 in /home/vautri_b/Projets/Projets_S1/ProgShell/Minishell1/Projet
##
## Made by Bertrand Vautrin
## Login   <vautri_b@epitech.net>
##
## Started on  Tue Jan 12 10:39:09 2016 Bertrand Vautrin
## Last update Thu Jun 16 23:54:44 2016 Florian Vincent
##

CC	=	gcc -g3

RM	=	rm -rf

MAKE	=	make -C

SRCS	=	My_Printf/my_putchar_spe.c \
		My_Printf/my_put_nbr_spe.c \
		My_Printf/my_putstr_spe.c \
		My_Printf/fcts_display.c \
		My_Printf/fcts_display2.c \
		My_Printf/fcts_display3.c \
		My_Printf/fcts_init.c \
		My_Printf/my_printf.c \
		gnl/get_next_line.c \
		srcs42/my_list/create_list.c \
		srcs42/my_list/alias_list.c \
		srcs42/tree_check.c \
		srcs42/tree_check_fcts.c \
		srcs42/tree_check_fcts2.c \
		srcs42/tree_exect_fcts.c \
		srcs42/tree_exect_fcts2.c \
		srcs42/tree_exect.c \
		srcs42/build_tree.c \
		srcs42/basic2.c \
		srcs42/cut_string.c \
		srcs42/red.c \
		srcs42/is_separator.c \
		srcs42/bordel.c \
		srcs42/my_alphanumeric.c \
		srcs42/auto_completion/auto_completion.c \
		srcs42/my_globing.c \
		srcs42/my_exit.c \
		srcs/main.c \
		srcs/my_str_to_wordtab.c \
		srcs/basic.c \
		srcs/builtins.c \
		srcs/cd.c \
		srcs/init.c \
		srcs/env.c \
		srcs/updated_basic.c \
		srcs/sig.c \
		srcs/exec.c \
		srcs/check.c \
		srcs/find.c \
		srcs/check2.c \
		srcs/my_echo_fptr.c \
		srcs/my_backslash.c \
		srcs/my_backslash2.c \
		srcs/my_backslash3.c \
		srcs/echo.c \
		srcs/export.c \
		srcs/alias.c \
		srcs/42shrc.c \
		srcs/my_show_wordtab.c \
		srcs/my_wordtab_cat.c \
		srcs/tree_exect_command.c \
		srcs/my_prompt.c \
		srcs/getch.c \
		srcs/ncurses.c \
		srcs/ptr_fct.c \
		srcs/ptr_fct2.c \
		srcs/getch_bis.c \
		srcs/built_echo.c \
		srcs/historique.c

CFLAGS	+=	-I includes/ -Wall -Werror -Wextra -lncurses

OBJS	=	$(SRCS:.c=.o)

LIB	=	lib/my

NAME	=	42sh

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
