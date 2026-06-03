#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list	{
	struct s_list	*next;
	char			c;
} t_list;

void	ft_lstadd_back(t_list **tail, char c);

#endif