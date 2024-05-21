/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:34:18 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/21 18:34:19 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "tools.h"

int	check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check(str[i], charset))
			i++;
	}
	return (i);
}

int	ft_strlen_split(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check(str[i], charset))
		i++;
	return (i);
}

char	*word(char *str, char *charset)
{
	int		i;
	char	*mot;

	mot = (char *)malloc((ft_strlen_split(str, charset) + 1) * sizeof(char));
	i = -1;
	while (++i < ft_strlen_split(str, charset))
		mot[i] = str[i];
	mot[i] = '\0';
	return (mot);
}

char	**ft_split(char *str, char *charset)
{
	char	**piece;
	int		i;

	i = 0;
	piece = (char **)malloc((count_str(str, charset) + 1) * sizeof(char *));
	while (*str)
	{
		while (*str && check(*str, charset))
			str++;
		if (*str)
		{
			piece[i] = word(str, charset);
			i++;
		}
		while (*str && !check(*str, charset))
			str++;
	}
	piece[i] = 0;
	return (piece);
}
/*
#include <stdio.h>
//./a.out "Oh5564my56412I0don't57895know566427why137566exfour9doesn't2work"
//"0123456789" | cat -e
int	main(int argc, char **argv)
{
	int	i;
	char	**separated;
	(void)	argc;

	separated = ft_split(argv[1], argv[2]);
	i = -1;
	while (separated[++i])
	{
		printf("%s\n", separated[i]);
		free(separated[i]);
	}
	free(separated);
	return (0);
}
*/
