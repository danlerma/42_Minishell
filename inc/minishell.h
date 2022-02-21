#ifndef MINISHELL_H

# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
	1 -> commando
	2 -> redirecciones
	3 -> pipes
	4 -> infile
	5 -> outfile
	6 -> texto
	7 -> builtins
	
	El comando si tiene una opcion debe estar seguido, en el parseo se une para
	el execuve.
	Ex: "ls -la" o "wc -l"
*/

typedef struct s_argv
{
	int				type;
	char			*s_arg;
	struct s_argv	*next;
}t_argv;

#endif
