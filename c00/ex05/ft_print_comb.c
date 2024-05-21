/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:30:44 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/08 15:30:46 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	pr_mot(char c)
{
	write(1, &c, 1);
}

void	pr_comb(char a, char b, char c)
{
	pr_mot(a + '0');
	pr_mot(b + '0');
	pr_mot(c + '0');
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				pr_comb(a, b, c);
				if (a == 7 && b == 8 && c == 9)
				{
					return ;
				}
				write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
