/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slario <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:24:46 by slario            #+#    #+#             */
/*   Updated: 2024/02/25 18:01:31 by slario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "tools.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_mini_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (str[i] != '\0' || str[i] == '+' || str[i] == ' '
			|| (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] != '\0' && str[i] <= '0' && str[i] >= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}
