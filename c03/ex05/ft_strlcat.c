/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:21:25 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/14 10:21:26 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*Cut the "size" amount from dest, and then put src as many as we can.
And returns the length of (src + min(dest, size)).*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s_len;
	unsigned int	d_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (s_len + size);
	while (src[i] && i < size - d_len - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (s_len + d_len);
}
/*
// cc with -lbsd
#include <bsd/string.h>
#include <stdio.h>

int main (void)
{
	char dest[100] = "Why is ";		//word count = 7
	char src[] = "Moulinette the way she is?";//word count = 26
	
	char dest1[] = "Why is ";		//word count = 7
    	printf("%u \n", ft_strlcat(dest, src, 0)); //%i for integer
	printf("%s \n", dest);

	printf("%zu \n", strlcat(dest1, src, 0)); //%i for integer
	printf("%s \n", dest1);
}
*/
