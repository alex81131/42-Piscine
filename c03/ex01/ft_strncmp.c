/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:00:16 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/12 19:00:17 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*If 2 strings are different, s1[i] - s2[i] automatically doesn't give 0.
Not 0: compare the ASCII of the characterof the 2 strings*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
//have to be || between s1 and s2, cuz they could have different length
//and just return 1 or -1 (not sure if it's a must
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("2 chaines de charactere et un int svp");
		return (1);
	}

	int	n;
	
	n = atoi(argv[3]);	
	printf("%d\n", ft_strncmp(argv[1], argv[2], n));
	printf("%d\n", strncmp(argv[1], argv[2], n));
	return (0);
}
*/
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("auf0", "auf0Z", 5));
	printf("%d\n", strncmp("auf0", "auf0Z", 5));
	return (0);
}
*/
