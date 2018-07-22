/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 19:25:59 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 17:06:22 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static short	find_pair_down(int mas[4][4], int x, int y)
{
	short	step;

	step = 1;
	while ((y - step) >= 0 && mas[x][y - step] == 0)
		step++;
	if ((y - step >= 0) && mas[x][y - step] == mas[x][y])
	{
		mas[x][y] *= 2;
		mas[x][y - step] = 0;
		return (mas[x][y]);
	}
	return (0);
}

static void		push_all_down(int mas[4][4], int *x)
{
	short	step;
	short	i;
	short	j;

	j = 4;
	while (--j >= 0)
	{
		i = -1;
		while (++i < 4)
		{
			step = 0;
			if (mas[i][j] == 0)
				while (j - step >= 0 && !mas[i][j - step])
					step++;
			if (step && j - step >= 0)
			{
				mas[i][j] = mas[i][j - step];
				mas[i][j - step] = 0;
				*x += 1;
			}
		}
	}
}

int				move_down(int mas[4][4], t_result *res)
{
	short	i;
	short	j;
	int		x;

	x = 0;
	j = 4;
	while (--j >= 0)
	{
		i = -1;
		while (++i < 4)
		{
			if (mas[i][j] != 0)
				x += find_pair_down(mas, i, j);
		}
	}
	res->result += x;
	push_all_down(mas, &x);
	print_result(res);
	return (x);
}
