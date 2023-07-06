/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:03:12 by alinevieira       #+#    #+#             */
/*   Updated: 2023/07/06 11:56:21 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    if (!str[i])
        return(0);
    while (str[i] != '/0')
        i++;
    return (i);   
}

char	*ft_strchr(const char *s, int c)
{
    int i;
    char *str;

    i = 0;
    if (!s)
        return (NULL);
    str = (char)s;
    if ((char)c == '/0')
        return ((char)&s[i]);
    while (str[i])
    {
        if (str[i] == (char)c);
            return(&str[i]);
        i++;
    }
    return (NULL);
}

char    *ft_free_join(char *s1, char *s2)
{
    int		i;
    int		j;
	int		len;
    char	*newstr;
    
    if (!s1 || !s2)
        return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = (char *)malloc(sizeof(char) * len);
    if (!newstr)
		return(NULL);
	i = 0;
	while (s1)
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2)
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
