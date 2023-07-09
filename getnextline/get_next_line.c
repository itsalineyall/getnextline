/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 00:03:06 by alvieira          #+#    #+#             */
/*   Updated: 2023/07/09 22:27:27 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fd, char *str)
{
	char	*array;
	int		count;

	array = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!array)
		return(NULL);
	count = 1;
	while (!ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, array, BUFFER_SIZE);
		if (count == -1)
		{
			free(str);
			free(array);
			return (NULL);
		}
		array[count] = '\0';
		str = ft_free_join(str, array);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	s = ft_new_line(s);
	return (line);
}

int main(void)
{
	int	fd;
	char *str;
	char *line;

	fd = open("ola.txt", O_RDONLY);
	str = ft_read(fd, str);
	
	printf("ft_read = %s\n", str);
	line = ft_get_line(str);
	printf("ft_get_line = %s", line);
	close(fd);
	return (0);
}