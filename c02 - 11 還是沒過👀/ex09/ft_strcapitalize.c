/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:46:14 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/11 15:46:15 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	nbwords(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (nbwords(str[i]))
		{
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
			i++;
			while (nbwords(str[i]))
			{
				if ('A' <= str[i] && str[i] <= 'Z')
					str[i] += 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}
/*
//Numbers are followed by words and counted as words.
#include <stdio.h>
int	main()
{
	char	str[]="O(El1~Mq'Jyq9~>`Ghmr9P-Yd[Ih   ";

	printf("Original   :<%s>\n", str);
	ft_strcapitalize(str);
	printf("Capitalized:<%s>\n", str);

	return (0);
}
*/
