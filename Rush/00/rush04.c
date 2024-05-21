/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sviallon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:00:32 by sviallon          #+#    #+#             */
/*   Updated: 2024/02/10 16:00:44 by sviallon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(void);

void	write_line(int left, int mid, int right, int x)
{
	int	a;

	a = 0;
	if (x > 0)
	{
		write(1, &left, 1);
	}
	while (a < (x - 2))
	{
		write(1, &mid, 1);
	a++;
	}
	if (x > 1)
	{
		write(1, &right, 1);
	}
}

void	rush(int x, int y)
{
	int	a;

	a = 0;
	if (x >= 1 && y >= 1)
	{
		write_line ('A', 'B', 'C', x);
		ft_putchar ('\n');
		while (a < y - 2)
		{
			write_line ('B', ' ', 'B', x);
			ft_putchar ('\n');
			a++;
		}
	}
	if (y > 1)
	{
		write_line ('C', 'B', 'A', x);
		ft_putchar ('\n');
	}
}
