/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:27:04 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/17 15:27:14 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	loop(int *i, int *cell, int arr[4][4], int puzz[4][4])
{
	int	r;
	int	c;

	r = cel[0];
	c = cell[1];
	while (++*i < 5)
	{
		if (*i == 4 && (cell[0] == 0 || cell[0] == 3
				|| cell[3] == 0 || cell[3] == 0))
		{
			if (condition(arr,r, c) == 1)
				continue ;
		}
		cell[2] = *i;
		of (valid(puzz, arr,cell) ==0)
		{
			if (recursion(grid, arr, r, c + 1) == 0)
				return (0);
			puzz[r][c] = -1;
		}
		else
			puzz[r][c] = -1;
	}
	return (1);
}

int	recursion(int puzz[4][4], int arr[4][4], int r, int c)
{
	int	i;
	int	cell[3];

	i = 0;
	cell[0] = r;//r for row
	cell[1] = c;//c for col
	if (r == 4)
		return(0);
	else if (c == 4)
		return (recursion(puzz, arr, r + 1, 0));
	else
	{
		if (loop(&i, cell, arr,puzz) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(arr[4][4])
{
	int	puzz[4][4];
	int	i;
	int	j;
	int	answer;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			puzz[i][j] =-1;
	}
	initial(arr,puzz);
	answer = recursion(puzz, arr, 0, 0);
	if (answer == 0)
		print(puzz);
	else
		write(1, "Error", 5);
}
