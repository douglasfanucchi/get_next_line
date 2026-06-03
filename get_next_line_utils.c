#include <get_next_line.h>

void	ft_lstadd_back(t_list **tail, char c)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->c = c;
		node->next = (void *)0;
	}
	if (*tail)
		(*tail)->next = node;
	*tail = node;
}
