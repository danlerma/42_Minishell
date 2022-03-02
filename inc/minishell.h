#ifndef MINISHELL_H

# define MINISHELL_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;90m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

# include "../lbft/libft.h"

typedef struct s_lst
{
	char			**argv;
	int				*type;
	int				*flag;
	struct s_lst	*next;
}t_lst;

typedef struct s_mirage
{
	char				*var;
	char				*name;
	char				*value;
	struct	s_mirage	*next;
}t_mirage;

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <execute.h>
# include <parse.h>
# include <readline/readline.h>
# include <readline/history.h>
// # include "../pipes/inc/pipes.h"


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

// typedef struct s_argv
// {
// 	int				type;
// 	char			*s_arg;
// 	struct s_argv	*next;
// }t_argv;

// char	**ft_split_mod_2(char const *s, char c);
// char	**split_data(char const *s);
// t_list	*make_lst(t_list *lst, char const *s);
// t_lst	*create_nodes(char **argv);
// t_lst	*set_data_nodes(t_lst *nodes);
// void	free_nodes(t_lst *nodes);
// void	free_argv(char **argv, char *str);

#endif