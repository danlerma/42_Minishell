#ifndef MINISHELL_H

# define MINISHELL_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE "\033[1;34m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;90m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

# include "../lbft/libft.h"
# include <general.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <execute.h>
# include <parse.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lbft/libft.h"

#endif
