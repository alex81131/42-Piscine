/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:20:06 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/20 18:20:07 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	full_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		if (strs[i])
		{
			len += ft_len(strs[i]);
			if (i < size - 1)
				len += ft_len(sep);
		}
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc((full_len(size, strs, sep) + 1) * sizeof(char));
	if (!arr)
		return (0);
	while (i < full_len(size, strs, sep) + 1)
	{
		arr[i] = '\0';
		i++;
	}
	i = 0;
	while (i < size)
	{
		ft_strcat(arr, strs[i]);
		if (i < size - 1)
			ft_strcat(arr, sep);
		i++;
	}
	return (arr);
}
/*
// *arr = 0 is to initialize arr. If arr = 0, it'll point to NULL,
//and it'll lead to segmentation fault.
//
//The reason that it's not *str[i] in j += ft_len(strs[i]),
//is that you don't mix the usage of * and [i].
//If you pass only one parameter as strs[i],it stands for the string number,
//and then strs[i][j] is the value on the string.
#include <stdio.h>
//(char *)malloc(sizeof(char)) assigns a memory of one-char sized
int	main(void)
{
	char	*strs[4] = {"Hello", "my friend", "you are", "awesome!"};
	char	*separator;
	char	*result;
	int	size;

	size = 4;
	separator = "__";
	result = ft_strjoin(size, strs, separator);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
