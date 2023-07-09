/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline_soraya.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:03:12 by alvieira          #+#    #+#             */
/*   Updated: 2023/07/09 18:50:56 by alvieira         ###   ########.fr       */
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

char *get_next_line(int fd)
{
    char *line;           // Variável para armazenar a linha lida
    static char *s;       // Variável estática para armazenar o estado dos dados lidos

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);    // Verifica se o descritor de arquivo é inválido ou BUFFER_SIZE é zero/negativo

    s = ft_read(fd, s);   // Chama a função ft_read para ler dados do arquivo e atualiza a variável s

    if (!s)
        return (NULL);    // Verifica se ocorreu algum erro durante a leitura ou se não há mais linhas a serem lidas

    line = ft_get_line(s);    // Extrai uma linha completa de caracteres a partir dos dados contidos em s
    s = ft_new_line(s);       // Atualiza s para remover a linha já lida e manter os dados restantes

    return (line);        // Retorna a linha lida
}


int main(void)
{
    int fd;
    // char *line;
	
    fd = open("ola.txt", O_RDONLY); // ira abrir o arquivo test.txt para leitura
	if (fd == -1)
	{
		printf("Error\n");
		return (1);
	}
	// line = get_next_line(fd);
	// while(line)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }

	char *str = ft_read(fd, NULL);
	printf("ft_read = %s", str);
	free(str);
	return (0);
}