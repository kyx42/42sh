/*
1;4201;0c** macro.h for  in /home/mesqui_v/rendu/Tek1/S2/PSU/42sh/PSU_2015_42sh
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri May 27 15:46:44 2016 vincent mesquita
** Last update Tue Aug 16 16:14:27 2016 Florian Vincent
*/

#ifndef MACRO_H_
# define MACRO_H_

# define EXIT_VALUE		(-42)
# define EXIT_ERROR		1
# define NB_BUILT		(9)

# define DEFAULT_PATH		("PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/\
bin:/usr/heimdal/sbin")
# define SEGMENTATION_FAULT	"Segmentation fault\n"
# define SEGFAULT_EXIT		139
# define FLOATING_EXCEPTION	"Floating exception\n"
# define FLOATING_EXCEPT_EXIT	138

/*
** ALIAS
*/

# define XALIAS			data->alias
# define ALIAS_NAME		data->alias_name
# define ALIAS_ERR		"Not able to add it (memory error)\n"
# define ALIAS_ARGS_ERR		"Usage: alias alias-name "
# define ALIAS_CHANGE_ERR	"Not able to change it (memory error)"

/*
** 42shrc
*/

# define CREAT			O_RDWR | O_CREAT
# define CHECK			O_RDWR | O_EXCL | O_CREAT
# define PERM			S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH \
  | S_IRGRP | S_IWGRP
# define RC			"/.42shrc"
# define HOME			"HOME"
# define OPEN_ERROR		"Open failed\n"

/*
** Syscall failed
*/

# define READ_ERR	"Read failed\n"
# define MALLOC_ERR	"Malloc failed\n"
# define OPEN_ERR	"Open failed\n"

/*
** SHELL SEPARATOR
*/

# define SPACE			' '
# define TAB			'\t'

/*
** SHELL SYMBOLS
*/

# define SEMICOLON		";"
# define SLASH			'/'
# define PIPE			"|"
# define LEFT_REDI		"<"
# define DLEFT_REDI		"<<"
# define RIGHT_REDI		">"
# define DRIGHT_REDI		">>"

/*
** BUITIN NAMES
*/

# define ENV			"env"
# define SETENV			"setenv"
# define UNSETENV		"unsetenv"
# define CD			"cd"
# define DOTDOT			".."
# define EXIT			"exit"
# define EXIT_MESSAGE		"exit\n"
# define XECHO			"echo"
# define EXPORT			"export"
# define ALIAS			"alias"

/*
** Builtin errors
*/

# define SETENV_WRONG_VALUE	"setenv: Variable name must \
contain alphanumeric characters.\n"
# define SETENV_ARGS_ERR	"setenv: Too many arguments.\n"
# define UNSETENV_ARGS_ERR	"unsetenv: Too many arguments.\n"
# define EXIT_ERR		"exit: Expression Syntax.\n"
# define CD_ERR			"cd: Too many arguments.\n"
# define CD_NO_SUCH_FILE	": No such File or Directory\n"
# define CD_NO_DIR		": Not a directory.\n"
# define CD_E			"cd: "
# define CD_HOME_NOT_SET	"cd: HOME not set\n"
# define CD_OLDPWD_NOT_SET	"cd: OLDPWD not set\n"
# define CD_DASH		"-"
# define CD_TILDE		"~"
# define CD_PERMISSION_DENIED	": Permission denied.\n"
# define EXPORT_INVALID		"42sh: Invalid export argument\n"

/*
** Env var
*/

# define HOME			"HOME"
# define OLDPWD			"OLDPWD"
# define PWD			"PWD"
# define PATH			"PATH"

/*
** Env var separator
*/

# define VAR_SEPARATOR		":"
# define SEMICOLON		";"
# define AND			"&&"
# define OR			"||"

/*
** Wrong command
*/

# define COMMAND_NOT_FOUND	": Command not found.\n"

/*
** Echo
*/

# define OCT			8
# define OCT_LENGTH		3
# define HEX			16
# define HEX_LENGTH		2

/*
** Redirection errors
*/

# define AMBIGUOUS_OUTPUT_REDI	"Ambiguous output redirect.\n"
# define MISSING_NAME_REDI	"Missing name for redirect.\n"

/*
** Ls
*/

# define LS			"ls"
# define LS_OPTIONS		"LS_OPTIONS"

/*
** glob
*/

# define GLOB_FLAG	GLOB_MARK | GLOB_BRACE

/*
** Input
*/

# define NB_CAPABILITY	6


#endif /* !MACRO_H_ */
