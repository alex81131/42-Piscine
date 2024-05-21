/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:08:30 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/19 09:08:30 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb > 0)
	{
		nb *= (ft_recursive_factorial(nb - 1));
		return (nb);
	}
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_recursive_factorial(-120));
	printf("%i\n", ft_recursive_factorial(5));
	return (0);
}
*/
