#include "libft.h"

t_node	*ft_lstnewfd(int fd, void	*content)
{
	t_node	*buf_lst;

	buf_lst = (t_node *)malloc(sizeof(t_node));
	if (!buf_lst)
		return (NULL);
	buf_lst->fd = fd;
	buf_lst->str = ft_strndup(content, 0);
	if (!buf_lst->str)
	{
		free(buf_lst);
		return (NULL);
	}
	buf_lst->next = NULL;
	return (buf_lst);
}
