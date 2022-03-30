/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/30 17:16:23 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H

# define EXECUTE_H

# include <minishell.h>

typedef struct s_command
{
	int		nc;
	int		pos;
	char	**cmd;
	char	*com;
}t_command;

typedef struct s_info
{
	int			nlst;
	int			built;
	int			iter;
	char		**paths;
	char		**path;
	int			**pipe;
	int			pos;
	int			np;
	int			ex;
	int			fd_in;
	int			fd_out;
	char		**env;
	t_command	*cmd;
}t_info;

//execute
void	exec(t_lst *lst, t_env **env);

//init_comands
void	init_structs(t_lst **lst, t_info *info, t_mirage *env);
void	init_commands(t_lst *lst, t_info *info);
t_env	*init_env(void);

//make process
void	make_process(t_info *info, t_lst *lst, t_env **env);

//execute_cmd
void	search_command(t_info *info, t_lst *lst, char *com, t_env **env);

//norm_exec
void	norm_cmd_child(t_lst *lst, t_info *info, char *com);
void	norm_cmd_father(t_info *info, char **cmd);

//show list
void	s_list(t_lst *lst);
void	s_mirage(t_mirage *lst);

//pipes utils
char	**find_path(char **environ);
void	valid_path(t_info *info);
char	**create_cmd(t_lst *lst, t_info *info);
void	error_cmd(char *str);

//command
void	commands(t_info *info, t_lst *lst, t_env **env);

//lst
int		lstsize(t_lst *lst);
void	lstadd_back(t_lst **lst, t_lst *new);
t_lst	*lstlast(t_lst *lst);
void	lstdelone(t_lst *lst, void (*del)(void*));
void	lstclear(t_lst **lst, void (*del)(void *));

//file.c
void	check_redir(t_info *info, t_lst *lst, int n);

//here.c
void	check_here(t_info *info, t_lst *lst);

//argv_temp
t_lst	*argv_init_temp(char **argv, int argc);

//output
void	output_check(pid_t son, int multiple_comands);

//signals
void	signal_main(void);
void	signal_heredoc(void);
void	signal_son(void);
void	signal_ing(void);

#endif
