/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chop_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slario <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:55 by slario            #+#    #+#             */
/*   Updated: 2024/02/24 23:28:48 by slario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**keyword(char *str);
int	ft_strlen_split(char *str, char *charset);

int	dict_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**mag(char *str)
{
	char	**dico;
	int	d_len;
	int	nb_len;
	int	i;
	int	word_len;
	char	**block;
	int	length;

	dico = keyword("numbers.dict");
	d_len = dict_len(dico);
	nb_len = ft_strlen_split(str, "");
	printf("nb_len is %i\n", nb_len);
	nb_len /= 3;
	printf("nb_len is %i\n", nb_len);
	block = (char **)malloc((nb_len + 1) * sizeof(char *));
	i = -;
	while (++i < nb_len)
		block[i] = "0";
	i = 0;
	while (block[i])
	{
		printf("block[%i] is %s\n", i, block[i]);
		i++;
	}
	length = dict_len(block);
	printf("There are %i blocks\n", length);
	i = 0;
	while (block[i])
	{
		word_len = ft_strlen_split(dico[d_len - 11 - i], "");
		printf("word_len is %i\n", word_len);
		block[i] = (char *)malloc((word_len) * sizeof(char));
		block[i] = dico[d_len - 11 - i];
		printf("block[%i] is %s\n", i, block[i]);
		i++;
	}
	block[i] = 0;
	return (block);
}

int	main()
{
	char	*nbr = "156256789";
	int	i;
	char	**blocks;

	blocks = mag(nbr);
	i = -1;
	while (blocks[++i])
	{
		printf("%s\n", blocks[i]);
		free(blocks[i]);
	}
	free(blocks);
	return (0);
}
