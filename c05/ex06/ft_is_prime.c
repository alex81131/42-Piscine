/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:18:19 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/19 09:18:21 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 1;
	while (++i && (long)i * (long)i <= (long)nb)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}
/*
//Automatically includes 2 in the end

//Using "long", and using "while (!ft_is_prime(nb))"
//instead of loop "while(nb){if (ft_is_prime(nb) == 1)}"to avoid Timeout

//Remember it's i * i <= nb. Otherwise will take perfect squares as primes
#include <stdio.h>

int	main(void)
{
	printf("%i -> %i\n", 0, ft_is_prime(0));
	printf("%i -> %i\n", 1, ft_is_prime(1));
	printf("%i -> %i\n", 2, ft_is_prime(2));
	printf("%i -> %i\n", 6, ft_is_prime(6));
	printf("%i -> %i\n", 7, ft_is_prime(7));
	printf("%i -> %i\n", 2147483647, ft_is_prime(2147483647));
	return (0);
}
*/
