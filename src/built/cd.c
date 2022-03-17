#include<minishell.h>
/*
No es cambiar el environment, es hacer creer que lo has cambiado
Es un espejismo
*/
void	make_cd(t_lst *lst, t_info *info, t_env **env)
{
	char	**cmd;
	char	*home;

	/*
	Si no tiene nada de argumentos, solo el cd, por defecto se tiene que
	mover a la variable HOME
	Si meten cd -, hay que mostrar el ultimo cd hechom si es la primera vez,
	tiene que mostrar: bash: cd: OLDPWD not set
	si meten cd .., es mover arriba, lo unico que hay que hacer es actualizar
	el OLDPATH.
	Lo mismo pasa con .
	*/
	if (lst->argv[1] == NULL)
	{
		home = get_val_env((*env)->env, "HOME");
		if (home != NULL)
			chdir(home);
		else
			printf("cd: HOME not set\n");
	}
	else
	{
		cmd = create_cmd(lst, info);
		chdir(cmd[1]);
		free(cmd);
	}
}
