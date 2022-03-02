/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/24 12:53:45 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H

# define EXECUTE_H

# include <minishell.h>

// typedef struct s_lst
// {
// 	char			**argv;
// 	int				*type;
// 	int				*flag;
// 	struct s_lst	*next;
// }t_lst;

typedef struct s_command
{
	int		nc; //num de commandos totales (Reciclar)
	int		pos; //posicion del primer comando actual (Reciclar)
	char	**cmd; //comando a ejecutar(Reciclar)
	char	*com; //comando para el execuve(Reciclar)
}t_command;

typedef struct s_info
{
	int			nlst; //numero de nodos
	int			iter; //iterador de archivos heredoc
	char		**paths; //path env (sin modificar)
	char		**path; //path env (modificada)
	int			**pipe; //matriz de pipes
	int			pos; //posicion del nodo
	int			np; //numero de pipes para saber en cual estoy
	int			nh; //numero de heredoc
	t_command	*cmd; //puntero a estructura de commandos
}t_info;

/*
	1- comando simple -> cat, wc -w, ls...
	2- redirecion in <
	4- redireción out >
	5- archivo
	6- heredoc <<
	7- append >>
	8- texto



	TODO
	heredoc que pare con ctrl-D
	meter señales
	sacar errores en ejecucion
	eliminar PATH
	error de permisos
	flag para heredoc
*/

//execute
void	exec(t_lst *lst);

//init_comands
void	init_structs(t_lst **lst, t_info *info, char **environ);
void	init_commands(t_lst *lst, t_info *info);
t_env	*init_env();
//make process
void	make_process(t_info *info, t_lst *lst, char **environ);
// void	dir_process(t_info *info, t_lst *lst, char **environ);
//heredoc
void	do_here(t_lst *lst, t_info *info, char **environ);
//show list
void	s_list(t_lst *lst);
//pipes utils
char	**find_path(char **environ);
void	valid_path(t_info *info);
char	**create_cmd(t_lst *lst, t_info *info);
// void	open_pipes(t_info *info);
void	error(char *file);
//command
void	commands(t_info *info, t_lst *lst, char **environ);
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

//built
int	check_built(t_lst *lst, t_info *info, char **environ, char *com);
void	make_cd(t_lst *lst, t_info *info, char **environ, char *com);
void	make_exit(t_lst *lst, t_info *info, char **environ, char *com);
void	make_export(t_lst *lst, t_info *info, char **environ, char *com);



#endif
