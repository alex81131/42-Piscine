/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:41:00 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/21 09:41:02 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	new_len(int nbr, char *base)
{
	int		l;
	long	nb;
	int		len;

	nb = (long)nbr;
	l = ft_strlen(base);
	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= l)
	{
		nb /= l;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_base2(int nb_p, char *base, char *nb_f, int new_len)
{
	int		i;
	int		j;
	int		len_base;
	long	nb;

	nb = nb_p;
	i = 0;
	if (nb < 0)
	{
		nb_f[i] = '-';
		nb *= -1;
		i++;
	}
	j = new_len - 1;
	len_base = ft_strlen(base);
	while (nb >= len_base)
	{
		nb_f[j] = base[nb % len_base];
		nb /= len_base;
		j--;
	}
	if (nb < len_base)
		nb_f[i] = base[nb];
}
