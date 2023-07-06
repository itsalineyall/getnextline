/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:03:06 by alvieira          #+#    #+#             */
/*   Updated: 2023/07/06 12:27:33 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fdchar *str)
{
	char	*array;
	int		count;

	array = malloc(sizeof(char) * BUFFER_SIZE);
	if (!array)
		return(NULL);
	array = read(fd, )
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd <0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd);
	if (s == NULL)
		return (NULL);
	line = ft_new_line(s);
	s = get_next_line(s);
	return (s);
}

int main(void)
{
	int	fd;

	fd = open("ola.txt", O_RDONLY)
	
}