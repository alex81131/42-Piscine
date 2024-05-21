#include <stdlib.h>
#include <stdio.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	result = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (str[i] < '0' || '9' < str[i])
			break ;
	}
	if (count % 2 == 1)
		result = result * (-1);
	return (result);
}

int	*breakdown(char *str)
{//Remember to free this after use
	int	i;
	int	len;
	int	*nb;
	int	nbr;

	len = ft_strlen(str);
	i = 0;
	nbr = ft_atoi(str);
	if (nbr <= 20)
	{
		nb = (int *)malloc(sizeof(int));
		nb[0] = nbr;
	}
	else if (nbr < 100)
	{
		nb = (int *)malloc(2 * sizeof(int));
		nb[0] = (nbr / 10) * 10;
		nb[1] = (nbr - nb[0]);
	}
	else if (nbr < 1000)
	{
		nb = (int *)malloc(3 * sizeof(int));
		nb[0] = nbr / 100;
		nb[1] = (nbr - nb[0] * 100) / 10 * 10;
		nb[2] = (nbr - nb[0] * 100 - nb[1]);
	}
	else
		nb = 0;
	return (nb);
}

int	main(int ac, char **av)
{
	int	i;
	int	*nb;

	(void)ac;
	if (ac != 2)
		return (1);
	i = 0;
	nb = breakdown(av[1]);
	printf("%s", av[1]);
	printf(" = ");
	while (nb[i])
	{
		printf("%i ", nb[i]);
		i++;
	}
	free(nb);
	printf("\n");
	return (0);
}
