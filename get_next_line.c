#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return(size);
}

static void	ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
}

static int fill_buffer(char *buffer, int fd)
{
	int	readed;

	readed = read(fd, buffer, BUFFER_SIZE);
	if (readed >= 0)
		buffer[readed] = 0;
	return (readed);
}

static int move_bytes_into_buffer(char *buffer, int j)
{
	ft_memcpy(buffer, buffer + j + 1, ft_strlen(buffer + j + 1) + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_list		*line;
	t_list		*tail;
	size_t		j;
	char		*result;

	line = (void *)0;
	tail = (void *)0;
	j = 0;
	if (!buffer[0])
		fill_buffer(buffer, fd);
	while (buffer[j])
	{
		ft_lstadd_back(&tail, buffer[j]);
		if (!line)
			line = tail;
		if (buffer[j] == '\n' && move_bytes_into_buffer(buffer, j))
			break ;
		j++;
		if (!buffer[j] && fill_buffer(buffer, fd) >= 0)
			j = 0;
	}
	result = ft_lsttostr(line);
	ft_lstclear(line);
	return (result);
}
