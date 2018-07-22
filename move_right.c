/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:31:08 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 12:22:43 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static short	find_pair_right(int mas[4][4], int x, int y)
{
	short	step;

	step = 1;
	while ((x - step) >= 0 && mas[x - step][y] == 0)
		step++;
	if ((x - step >= 0) && mas[x - step][y] == mas[x][y])
	{
		mas[x][y] *= 2;
		mas[x - step][y] = 0;
		return (1);
	}
	return (0);
}

static void		push_all_right(int mas[4][4], short *x)
{
	short	step;
	short	i;
	short	j;

	i = 4;
	while (--i >= 0)
	{
		j = -1;
		while (++j < 4)
		{
			step = 0;
			if (mas[i][j] == 0)
				while (i - step >= 0 && !mas[i - step][j])
					step++;
			if (step && i - step >= 0)
			{
				mas[i][j] = mas[i - step][j];
				mas[i - step][j] = 0;
				*x += 1;
			}
		}
	}
}

short			move_right(int mas[4][4])
{
	short	i;
	short	j;
	short	x;

	x = 0;
	i = 4;
	while (--i >= 0)
	{
		j = -1;
		while (++j < 4)
		{
			if (mas[i][j] != 0)
				x += find_pair_right(mas, i, j);
		}
	}
	push_all_right(mas, &x);
	return (x > 0);
}
