/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:11:50 by alvieira          #+#    #+#             */
/*   Updated: 2023/06/07 16:32:16 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> //open e close | read e write

int main(void)
{
    int fd;

    fd = open("ola.txt", O_RDONLY); // ira abrir o arquivo test.txt para leitura

    printf("fd: %d\n", fd);
}