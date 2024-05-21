/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:07:57 by kyeh              #+#    #+#             */
/*   Updated: 2024/02/17 13:08:00 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(int arr[4][4])
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
		{
			c = arr[i][j] +'0';
			write(1, &c, 1);
			write(1, " ", 1);
		}
		c = arr[i][j] +'0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	if_one(int puzz[4][4], int i, int j)
{
	if (i == 0)
		puzz[0][j] = 4;
	else if (i == 1)
		puzz[3][j] = 4;
	else if (i == 2)
		puzz[j][0] = 4;
	else
		puzz[j][3] = 4;
}

void	inc_dec(int	puzz[4][4], int c, int up_down, int row_col)
{//For "4" case: print 1 2 3 4
	int	i;

	if (up_down == 0)
	{//	from left or top
		i = -1;
		while (++i < 4)
		{//print   1 2 3 4
			if (row_col == 0)//print rightwards
				puzz[c][i] = i + 1;
			else		//print downwards
				puzz[i][c] = i + 1;
		}
	}
	else//up_down == 1
	{//	from right or bottom
		i = 4;
		while (--i > -1)
		{//print   1 2 3 4 
			if (row_col == 0)//print leftwards
				puzz[c][i] = 4 - i;
			else		//print upwards
				puzz[i][c] = 4 - i;
		}
	}
}

void	put(int puzz[4][4], int *i, int *j, int arr[4][4])
{
	int	n;
	
	n = -1;
	if (arr[*i][*j] == 1)
		if_one(puzz, *i, *j);
	else if (*i == 0)
		inc_dec(puzz, *j, 0, 1);	//print downwards
	else if (*i == 1)
		inc_dec(puzz, *j, 1, 1);	//print upwards
	else if (*i == 2)
		inc_dec(puzz, *j, 0, 0);	//print rightwards
	else
		inc_dec(puzz, *j, 1, 0);	//print leftwards
}

void	initial(int arr[4][4], int puzz[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i <4)
	{
		j = -1;
		while(++j < 4)
		{//	We focus on when the conditionis 1 or 4 for now
			if (arr[i][j] == 1 || arr[i][j] == 4)
				put(puzz, &i, &j, arr);
		}
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void	loop(int *i, int *cell, int arr[4][4], int puzz[4][4])
{
	int	r;
	int	c;

	r = cell[0];
	c = cell[1];
	while (++*i < 5)
	{
		if (*i == 4 && (cell[0] == 0 || cell[0] == 3
				|| cell[1] == 0 || cell[1] == 3))
		{
			if (condition(arr,r, c) == 1)
				continue ;
		}
		cell[2] = *i;
		if (valid(puzz, arr, cell) == 0)
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
		if (loop(&i, cell, arr, puzz) == 0)
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
			puzz[i][j] == -1;
	}
	initial(arr,puzz);
	answer = recursion(puzz, arr, 0, 0);
	if (answer == 0)
		print(puzz);
	else
		write(1, "Error", 5);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int	main()
{
	int arr[4][4] = {{4, 3, 2, 1},{1, 2, 2, 2},{4, 3, 2, 1},{1, 2, 2, 2}};
	int puzz[4][4] = {{-1}};//   Initialize everything to 0.

	initial(arr, puzz);
	print(puzz);
	return 0;
}

