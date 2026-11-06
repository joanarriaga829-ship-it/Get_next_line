/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarriag <luarriag@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 00:20:07 by luarriag          #+#    #+#             */
/*   Updated: 2026/11/07 00:50:17 by luarriag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (ft_free_null(&stash));
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (ft_free_null(&stash));
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	if (ft_strchr(stash, '\n'))
		len = ft_strlen(stash, '\n') + 1;
	else
		len = ft_strlen(stash, '\0');
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_keep_rest(char *stash)
{
	size_t	len;
	size_t	start;
	char	*new_stash;
	size_t	i;

	if (ft_strchr(stash, '\n'))
	{
		start = ft_strlen(stash, '\n') + 1;
		len = ft_strlen(stash, '\0') - start;
		if (len == 0)
			return (ft_free_null(&stash));
		new_stash = malloc(sizeof(char) * (len + 1));
		if (new_stash == NULL)
			return (ft_free_null(&stash));
		i = 0;
		while (i < len)
		{
			new_stash[i] = stash[start + i];
			i++;
		}
		new_stash[i] = '\0';
		free(stash);
		return (new_stash);
	}
	return (ft_free_null(&stash));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (stash == NULL || stash[0] == '\0')
		return (ft_free_null(&stash));
	line = ft_extract_line(stash);
	stash = ft_keep_rest(stash);
	return (line);
}
