#include <get_next_line.h>

static size_t	ft_lstsize(t_list *node)
{
	size_t	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

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

char	*ft_lsttostr(t_list *node)
{
	size_t	i;
	size_t	size;
	char	*result;

	i = 0;
	size = ft_lstsize(node);
	result = (char *)malloc(sizeof(char) * (size + 1));
	while (node)
	{
		result[i] = node->c;
		node = node->next;
		i++;
	}
	result[size] = 0;
	return (result);
}

void	ft_lstclear(t_list *node)
{
	t_list	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}
