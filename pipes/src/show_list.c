#include <pipes.h>

void	s_list(t_lst *lst)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (lst != NULL)
	{
		i = 0;
		printf("Direction: %p\n", lst); 
		while (lst->argv[i])
		{
			printf("\tArgv(%d): %s\n\tType(%d): %d\n\n", i, lst->argv[i], i, lst->type[i]);
			i++;
		}
		printf("Next:      %p\n", lst->next);
		lst = lst->next;
	}
	printf("\n");
}
