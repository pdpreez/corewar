/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:50:47 by swilson           #+#    #+#             */
/*   Updated: 2018/06/21 08:51:39 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static t_list	*fileselector(t_list **file, int fd)
{
	t_list *temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	return (temp);
}

static void		makeline(char **line, t_list **node)
{
	int		i;
	int		j;
	char	*temp;

	temp = (char*)(*node)->content;
	j = ft_strlen(temp);
	i = 0;
	while ((temp[i] != '\n') && (temp[i] != '\0'))
		i++;
	*line = ft_strsub(temp, 0, i);
	if (j > i)
	{
		temp = (*node)->content;
		temp = ft_strsub(temp, i + 1, j);
		free((*node)->content);
		(*node)->content = ft_strdup(temp);
		free(temp);
	}
	else
		ft_strclr((*node)->content);
}

static char		*joinforfree(char *str1, char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	if (!str1 || !str2)
		return (NULL);
	i = -1;
	j = -1;
	len = ft_strlen((char*)str1) + ft_strlen((char*)str2);
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while ((char)str1[++i] != '\0')
		ret[i] = (char)str1[i];
	while ((char)str2[++j] != '\0')
		ret[i + j] = (char)str2[j];
	ret[i + j] = '\0';
	free(str1);
	return (ret);
}

static int		reading(const int *fd, char *buf, t_list **node)
{
	int		ret;

	while ((ret = read(*fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		(*node)->content = joinforfree((*node)->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*node;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if ((fd < 0) || !line || ((ret = read(fd, buf, 0)) < 0))
		return (-1);
	node = fileselector(&file, fd);
	ret = reading(&fd, buf, &node);
	if ((ret < BUFF_SIZE) && (ft_strlen(node->content) == 0))
		return (0);
	makeline(line, &node);
	return (1);
}
