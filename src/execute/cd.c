#include<minishell.h>
/*
No es cambiar el environment, es hacer creer que lo has cambiado
Es un espejismo
*/
void	make_cd(t_lst *lst, t_info *info, char *com)
{
	char	**cmd;

	/*
	Si no tiene nada de argumentos, solo el cd, por defecto se tiene que
	mover a la variable HOME
	Si meten cd -, hay que mostrar el ultimo cd hechom si es la primera vez,
	tiene que mostrar: bash: cd: OLDPWD not set
	si meten cd .., es mover arriba, lo unico que hay que hacer es actualizar
	el OLDPATH.
	Lo mismo pasa con .
	*/
	cmd = create_cmd(lst, info);
	chdir(cmd[1]);
	ft_free_malloc(cmd);
}

void	make_export(t_lst *lst, t_info *info, char *com)
{
	char	**cmd;

	cmd = create_cmd(lst, info);
	execve(com, cmd, info->env);
	printf("FEBKEWBJE\n");
}

void	make_exit(t_lst *lst, t_info *info, char *com)
{
	exit(0);
}
