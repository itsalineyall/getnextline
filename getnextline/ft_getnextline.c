/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:03:12 by alvieira          #+#    #+#             */
/*   Updated: 2023/06/07 16:30:29 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// a funcao get next line deve retornar uma linha lida de um file descriptor

char	*ft_read(int fd, char *str)
{
	char	*array;
	int		count;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	count = 1;
	//Enquanto o caractere de nova linha não for encontrado na string str e
	// o valor de count for diferente de zero, execute o código dentro do bloco de loop.
	while (!ft_strchr(str, '\n') && count != 0) // enquanto nao encontrar uma quebra de linha e nao chegar no final do arquivo
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
	free(array);
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
    int fd;
    char *line;

    fd = open("ola.txt", O_RDONLY); // ira abrir o arquivo test.txt para leitura
	if (fd == -1)
	{
		printf("Error\n");
		return (1);
	}
	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}