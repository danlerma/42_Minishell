#include<minishell.h>
/*
Si el valor de retorno <0, la cadena1 es menor que cadena2.
Si el valor de retorno> 0 indica menos de cadena1 cadena2.
Si el valor de retorno = 0, entonces cadena1 es igual a cadena2.
*/
static void sort_export(t_lst *lst, t_mirage *env)
{
	t_mirage	*aux;
	t_mirage	*iter;
	t_mirage	*node;
	int			i;
	int			len;

	i = 0;
	len = lstsize_env(env);
	iter = env;
	aux = env;
	node = env;
	while (len == 1)
	{
		printf("I(%d) env %s env %s aux %s\n", i, env->name, env->name, aux->name);
		if (ft_strncmp(iter->name, aux->next->name, ft_strlen(iter->name)) > 0)
		{
			node 
		}
		aux = aux->next;
		
		/*Si el numero es mas pequeño no es el que tiene tanata diferencia
			guardar el nodo con mas diferencia*/
		
		// if (i == len - 2)
		// {
		// 	printf("FINAL %d %s\n", i, env->name);
		// 	env = aux;
		// 	i = 0;
		// 	printf("FINAL %d %s\n", i, env->name);
		// 	break;
		// }
		// if (ft_strncmp(env->name, env->next->name, ft_strlen(env->name)) > 0)
		// {
		// 	printf(GREEN"env strcmp(antes) %s next %s"RESET"\n", env->name, env->next->name);
		// 	node = env;
		// 	env = env->next;
		// 	node->next = env->next;
		// 	env->next = node;
		// 	aux = env;
		// 	printf(GREEN"env strcmp(despues) %s next %s"RESET"\n", env->name, env->next->name);
		// }
		env = env->next;
		i++;
	}
	s_mirage(env);
}

//TODO Liberar
static void	new_variable(t_lst *lst, t_mirage **env)
{
	t_mirage	*temp;
	int			i;

	i = 1;
	while (lst->argv[i] != NULL)
	{
		if (ft_strchr(lst->argv[i], '=') != NULL)
		{
			temp = (t_mirage *)ft_calloc(1, sizeof(t_mirage));
			if (temp == NULL)
				exit(0);
			temp->var = ft_strdup(lst->argv[i]);
			split_variables(lst->argv[i], &temp);
			temp->next = NULL;
			if (get_name_env(*env, temp->name) != NULL)
				delete_var(env, temp->name);
			add_back_env(env, temp);
		}
		i++;
	}
}

void	make_export(t_lst *lst, t_info *info, t_mirage **env)
{
	//si solo hace export, lo dejamos para luego
	//si ya existe, es actualizar los datos
	printf("NLIST %d\n", lst->n_words);
	if (lst->n_words == 1)
	{
		printf("EN CONSTRUCCION\n");
		sort_export(lst, *env);
	}
	else
	{
		new_variable(lst, env);
	}
	// s_mirage(*env);

}
