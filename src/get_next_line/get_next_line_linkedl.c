#include "../../include/libft.h"

char	found_newline(t_list *list)
{
	while (list)
	{
		if (ft_strchr(list->content, '\n'))
			return (1);
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!found_newline(*list))
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0 || !char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_lstadd_back(list, ft_lstnew(buffer));
	}
}


int	len_to_newline(t_list *list)
{
	int		length;
	char	*newline_pos;

	length = 0;
	while (list)
	{
		newline_pos = ft_strchr(list->content, '\n');
		if (newline_pos)
		{
			length += (newline_pos - (char *)list->content) + 1;
			break ;
		}
		length += ft_strlen(list->content);
		list = list->next;
	}
	return (length);
}

char	*get_line(t_list *list, int fd)
{
	char	*next_str;
	int		str_length;
	char	*newline_pos;

	if (!list || !fd)
		return (NULL);
	str_length = len_to_newline(list);
	next_str = (char *)malloc(sizeof(char) * (str_length + 1));
	if (!next_str)
		return (NULL);
	next_str[0] = '\0';
	while (list)
	{
		newline_pos = ft_strchr(list->content, '\n');
		if (newline_pos)
		{
			ft_strncat(next_str, list->content, (size_t)(newline_pos
					- (char *)list->content + 1));
			break ;
		}
		ft_strcat(next_str, list->content);
		list = list->next;
	}
	return (next_str);
}


void	polish_list(t_list **list)
{
	char	*newline_pos;
	char	*remaining_str;
	t_list	*temp;

	while (*list)
	{
		newline_pos = ft_strchr((*list)->content, '\n');
		if (newline_pos)
		{
			remaining_str = ft_strdup(newline_pos + 1);
			free((*list)->content);
			(*list)->content = remaining_str;
			break ;
		}
		temp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
}

char	*get_next_line_linkedlist(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	next_line = get_line(list, fd);
	polish_list(&list);
	return (next_line);
}
