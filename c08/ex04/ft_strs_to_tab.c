/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:47:34 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/26 10:47:36 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*str;
	int					i;

	str = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].str = 0;
	str[i].copy = 0;
	return (str);
}
/*
#include <stdio.h>
//	./a.out "Moulinette" "is a" "LIE\!" | cat -e
int	main(int argc, char **argv)
{
	int			i;
	struct s_stock_str	*structs;

	structs = ft_strs_to_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("str[%d]\n", i);
		printf("\t| original : $%s$ @ %p\n", structs[i].str, structs[i].str);
		printf("\t|   copied : $%s$ @ %p\n", structs[i].copy, structs[i].copy);
		free(structs[i].copy);
		printf("\t|     size : %d\n", structs[i].size);
		i++;
	}
	free(structs);
}
*/
