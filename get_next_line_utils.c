/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarriag <luarriag@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 00:49:52 by luarriag          #+#    #+#             */
/*   Updated: 2026/11/07 00:53:18 by luarriag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*ss;
	unsigned char	cc;

	if (s == NULL)
		return (0);
	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == cc)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_free(char *stash, char *buf)
{
	size_t	len;
	char	*new_stash;
	size_t	i;
	size_t	j;

	len = ft_strlen(stash, '\0') + ft_strlen(buf, '\0');
	new_stash = malloc(sizeof(char) * (len + 1));
	if (new_stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	j = 0;
	if (stash)
	{
		while (stash[j])
			new_stash[i++] = stash[j++];
	}
	j = 0;
	while (buf[j])
		new_stash[i++] = buf[j++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*ft_free_null(char **stash)
{
	free(*stash);
	*stash = NULL;
	return (NULL);
}
