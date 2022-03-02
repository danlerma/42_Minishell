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

#endif