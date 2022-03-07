#include<minishell.h>
/*
No es cambiar el environment, es hacer creer que lo has cambiado
Es un espejismo
*/
void	make_cd(t_lst *lst, t_info *info, char *com)
{
	char	**cmd;
	(void)com;

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

void	make_exit(t_lst *lst, t_info *info, char *com)
{
	(void)com;
	(void)lst;
	(void)info;
	exit(0);
}
