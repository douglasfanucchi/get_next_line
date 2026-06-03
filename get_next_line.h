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

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **tail, char c);
char	*ft_lsttostr(t_list *node);
void	ft_lstclear(t_list *node);

#endif