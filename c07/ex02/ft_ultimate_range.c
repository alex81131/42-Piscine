/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:38:08 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/20 13:38:09 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (!*range)
	{
		*range = 0;
		return (-1);
	}
	i = -1;
	while (++i < max - min)
		(*range)[i] = min + i;
	return (max - min);
}
/*
#include <stdio.h>

int		main(void)
{
	int	min = 5;
	int	max = 10;
	int	*tab;
	int	size;
	int	i = 0;

	size = ft_ultimate_range(&tab, min, max);
	if (size >= 0)
	{while(i < size)
		{
			printf("%d, ", tab[i]);
			i++;
		}
		printf("\nSize of range is %i", size);
		free(tab);
	}
	return (0);
}
*/
