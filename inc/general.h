#ifndef GENERAL_H

# define GENERAL_H

typedef struct s_lst
{
	char			**argv;
	int				*type;
	int				*flag;
	struct s_lst	*next;
}t_lst;

typedef struct s_mirage
{
	char				*var;
	char				*name;
	char				*value;
	struct	s_mirage	*next;
}t_mirage;

#endif