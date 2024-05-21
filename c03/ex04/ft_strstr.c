/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:01:09 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/13 18:01:09 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i + j] && str[i + j] == to_find[j])
		{
			j++;
			if (j == str_len(to_find))
				return (&str[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "1AA_2A_3AA";
	char	s2[] = "3AA";
	
	printf("%s\n", ft_strstr(s1, s2));
	printf("%s", strstr(s1, s2));
}
*/
