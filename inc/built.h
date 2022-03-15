#ifndef BUILT_H

# define BUILT_H

# include <minishell.h>

// typedef struct s_env
// {
// 	t_mirage	*env;
// 	t_mirage	*ex_env;
// }t_env;

//env
char	*get_val_env(t_mirage *env, char *var);
void	delete_var(t_mirage **env, char *var);
char	*get_name_env(t_mirage *env, char *var);
void	insert_var(t_mirage **env, t_mirage *en);
void	change_val_env(t_mirage **env, char *var, char *value, char *all);

//utils env
int		check_built(t_lst *lst, t_info *info, char *com, t_env **env);
void	split_variables(char *variable, t_mirage **env);
char	**lst2array(t_mirage *env);
int		is_sorted(t_mirage **stack, int num);

//cd
void	make_exit(t_lst *lst, t_info *info, char *com);
void	make_cd(t_lst *lst, t_info *info, char *com);

//export
void	make_export(t_lst *lst, t_info *info, t_env **env);

//lst_env
t_mirage	*lstlast_env(t_mirage *lst);
void	add_back_env(t_mirage **lst, t_mirage *new);
void	lstdelone_env(t_mirage *lst, void (*del)(void*));
void	lstclear_env(t_mirage **lst, void (*del)(void *));
int		lstsize_env(t_mirage *lst);
t_mirage	*lstnew_env(t_mirage **env);
t_mirage	*new_node_env(char *cont);

//unset
void	make_unset(t_lst *lst, t_info *info, t_env **env);

//echo
void	make_echo(t_lst *lst);

//utils_export
void	show_export(t_mirage *env);
int	cond_export(t_mirage **head, t_mirage **env, int i);

#endif
