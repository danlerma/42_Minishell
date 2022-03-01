#ifndef MINISHELL_H

# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lbft/libft.h"
# include "../pipes/inc/pipes.h"

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

char	**ft_split_mod_2(char const *s, char c);
char	**split_data(char const *s);
t_list	*make_lst(t_list *lst, char const *s);
t_lst	*create_nodes(char **argv);
t_lst	*set_data_nodes(t_lst *nodes);
int		nodes_check_error(t_lst *list);
void	free_nodes(t_lst *nodes);
void	free_argv(char **argv, char *str);

#endif
