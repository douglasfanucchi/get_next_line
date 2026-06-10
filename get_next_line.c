#include "get_next_line.h"
#include <stdio.h>

static char	is_empty(t_buffer buffer)
{
	return (!buffer.bytes || !buffer.bytes[buffer.i]);
}

static int fill(t_buffer *buffer)
{
	int	readed;

	buffer->i = 0;
	if (!buffer->bytes)
		buffer->bytes = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readed = read(buffer->fd, buffer->bytes, BUFFER_SIZE);
	if (readed < 0)
	{
		buffer->free(buffer);
		return (readed);
	}
	buffer->bytes[readed] = 0;
	return (readed);
}

static void	free_buffer(t_buffer *buffer)
{
	free(buffer->bytes);
	buffer->bytes = NULL;
}

static char	get_next_char(t_buffer *buffer)
{
	return buffer->bytes[buffer->i++];
}

void	initialize_buffer(t_buffer *buffer, int fd)
{
	buffer->is_empty = is_empty;
	buffer->fill = fill;
	buffer->free = free_buffer;
	buffer->get_next_char = get_next_char;
	buffer->fd = fd;
	buffer->bytes = NULL;
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	t_list			*head;
	t_list			*tail;
	char			*result;

	tail = NULL;
	head = NULL;
	if (!buffer.fill)
		initialize_buffer(&buffer, fd);
	if (buffer.is_empty(buffer))
		buffer.fill(&buffer);
	while (!buffer.is_empty(buffer))
	{
		ft_lstadd_back(&tail, buffer.get_next_char(&buffer));
		if (!head)
			head = tail;
		if (tail->c == '\n')
			break ;
		if (buffer.is_empty(buffer))
			buffer.fill(&buffer);
	}
	if (buffer.is_empty(buffer))
		buffer.free(&buffer);
	result = ft_lsttostr(head);
	ft_lstclear(head);
	return (result);
}
