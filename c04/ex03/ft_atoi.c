/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:37:15 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/14 17:37:15 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	result = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (str[i] < '0' || '9' < str[i])
			break ;
	}
	if (count % 2 == 1)
		result = result * (-1);
	return (result);
}
/*
//Need to deal with white spaces first, and then +-, and then number.
//If finding white spaces after +-, return 0
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi("   -+--+012ab567"));
	printf("%d\n", ft_atoi("   -+--+ 012ab567"));
	printf("%d\n", ft_atoi("   -+--+Z012ab567"));
	printf("%d\n", ft_atoi("   -+--+012 ab567"));
}
*/
