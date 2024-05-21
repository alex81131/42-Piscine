/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:36:30 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/19 09:36:31 by kyeh             ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
/*
//Using "long", and using "while (!ft_is_prime(nb))"
//instead of loop "while(nb){if (ft_is_prime(nb) == 1)}"to avoid Timeout
#include <stdio.h>

int	main(void)
{
	int	nb;

	nb = 2147483600;	
	printf("Next prime after %i is %i\n", nb, ft_find_next_prime(nb));
	return (0);
}
*/
