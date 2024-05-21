/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slario <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:30:19 by slario            #+#    #+#             */
/*   Updated: 2024/02/24 21:57:49 by slario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "tools.h"

int	valid_dict(char **str)
{
	int	i;
	char	**dico;

	i = 0;
	dico = keyword("numbers.dict");
	while ((!str || !dico) && str[i] == dico[i])
		i++;
	return (dico[i] - str[i]);
}

int	main(int argc, char **argv)
{

	if (argc == 1 || argc >= 4)
		write(1, "Input Error\n", 12);
	else if (argv[1][0] == '-' || argv[2][0] == '-')
		write(1, "Error\n", 6);
	else if (argc == 2)
	{
		chop_chop(argv[1]);
	}
	else if (argc == 3 && valid_dict(&argv[1]) == 0)
	{
		chop_chop(argv[2]);
	}
}
