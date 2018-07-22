/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:32:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 12:22:31 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static short	find_pair_left(int mas[4][4], int x, int y)
{
	short	step;

	step = 1;
	while ((x + step) < 4 && mas[x + step][y] == 0)
		step++;
	if ((x + step < 4) && mas[x + step][y] == mas[x][y])
	{
		mas[x][y] *= 2;
		mas[x + step][y] = 0;
		return (1);
	}
	return (0);
}

static void		push_all_left(int mas[4][4], short *x)
{
	short	step;
	short	i;
	short	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
		{
			step = 0;
			if (mas[i][j] == 0)
				while (step + i < 4 && !mas[i + step][j])
					step++;
			if (step && step + i < 4)
			{
				mas[i][j] = mas[i + step][j];
				mas[i + step][j] = 0;
				*x += 1;
			}
		}
	}
}

short			move_left(int mas[4][4])
{
	short	i;
	short	j;
	short	x;

	i = -1;
	x = 0;
	while (++i < 3)
	{
		j = -1;
		while (++j < 4)
		{
			if (mas[i][j] != 0)
				x += find_pair_left(mas, i, j);
		}
	}
	push_all_left(mas, &x);
	return (x > 0);
}
