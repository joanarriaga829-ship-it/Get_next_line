/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luarriag <luarriag@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:40:01 by luarriag          #+#    #+#             */
/*   Updated: 2026/11/07 00:45:28 by luarriag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_extract_line(char *stash);
char	*get_next_line(int fd);
char	*ft_free_null(char **stash);
char	*ft_keep_rest(char *stash);
char	*ft_read_to_stash(int fd, char *stash);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char *stash, char *buf);
size_t	ft_strlen(const char *s, char c);

#endif
