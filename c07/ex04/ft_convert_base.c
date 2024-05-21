/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:40:54 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/21 09:40:55 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr_base2(int nb, char *base, char *nbr, int new_len);
int		new_len(int nbr, char *base);

int	base_check(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = -1;
	while (base[++i])
	{
		if ((9 <= base[i] && base[i] <= 13) || base[i] == 32
			|| base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j])
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (i);
}

int	white_neg(char *str, int *ptr_i)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && ((9 <= str[i] && str[i] <= 13) || str[i] == 32))
		i++;
	j = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	*ptr_i = i;
	if (j % 2 == 1)
		return (-1);
	else
		return (1);
}

int	indice(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (c == base[i])
			return (i);
	}
	return (-1);
}

int	atoi_base(char *nbr, char *base_from)
{
	int	i;
	int	j;
	int	deci_n;
	int	symbol;
	int	leng_b;

	i = 0;
	symbol = white_neg(nbr, &i);
	deci_n = 0;
	j = indice(nbr[i], base_from);
	leng_b = base_check(base_from);
	while (j != -1)
	{
		deci_n = (deci_n * leng_b) + j;
		i++;
		j = indice(nbr[i], base_from);
	}
	deci_n *= symbol;
	return (deci_n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		len;
	char	*str;
	int		i;

	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (0);
	nb = atoi_base(nbr, base_from);
	len = new_len(nb, base_to);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < (len + 1))
		str[i] = '\0';
	ft_putnbr_base2(nb, base_to, str, len);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*nbr = "   -+-+-42f25";
	char	*base_from = "0123456789";
	char	*base_to = "0123456789abcdef";
	char	*output;
	
	output = ft_convert_base(nbr, base_from, base_to);
	printf("%s", output);
	free(output);
	return (0);
}
*/
