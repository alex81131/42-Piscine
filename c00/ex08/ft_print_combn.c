/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:49:53 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/22 18:49:54 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check_print(int *tab, int n)
{
	int	i;
	int	check;

	i = 1;
	check = 1;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i])
			check = 0;
		i++;
	}
	if (check)
	{
		i = 0;
		while (i < n)
			ft_putchar(tab[i++] + '0');
		if (tab[0] < 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	if (n < 0 || 10 < n)
		return ;
	i = 0;
	while (i < n)
		tab[i++] = 0;
	while (tab[0] <= 10 - n && 0 < n && n < 10)
	{
		check_print(tab, n);
		tab[n - 1]++;
		i = n - 1;
		while (i)
		{
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
			i--;
		}
	}
}
/*
//ie. n = 2: we start with 00 and then +1 at the last element each time,
//(01, 02, 03...) and make sure that it rotates in a decimal manner.
//If it's in order, we print it, and then we continue to +1 and print
//those who meet our criteria.

//tab[10] to pass Norminette, and we don't care about the 0s on the right
//that we don't use, cuz by while (i < n) in check_print we only print
//what we've used. And it's what's printed that matters, so it's ok! :)
int	main (void)
{
	ft_print_combn(2);
	return (0);
}
*/
