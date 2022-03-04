#include<minishell.h>
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
			{
				printf("SON IGUALES\n");
				delete_var(env, temp->name);
			}
			add_back_env(env, temp);
		}
		i++;
	}
}

void	make_export( t_lst *lst, t_info *info, t_mirage **env)
{
	//si solo hace export, lo dejamos para luego
	//si ya existe, es actualizar los datos
	printf("NLIST %d\n", lst->n_words);
	if (lst->n_words == 1)
		printf("EN CONSTRUCCION\n");
	else
	{
		new_variable(lst, env);
	}
	// s_mirage(*env);

}
