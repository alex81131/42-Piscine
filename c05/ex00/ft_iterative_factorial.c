/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:08:21 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/19 09:08:23 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	while (nb > 0)
		i = i * (nb--);
	return (i);
}
/*
//Automatically includes when nb == 0
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_iterative_factorial(-120));
	printf("%i\n", ft_iterative_factorial(5));
	return (0);
}
*/
