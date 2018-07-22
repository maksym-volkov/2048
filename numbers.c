/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:15:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 18:37:22 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_number(int mas[4][4])
{
	short	num_pos;

	srand(time(NULL));
	num_pos = rand() % 16;
	while (mas[num_pos / 4][num_pos % 4] != 0)
		num_pos = rand() % 16;
	mas[num_pos / 4][num_pos % 4] = (rand() % 8 == 4) ? 4 : 2;
}

void	create_numbers(int mas[4][4], WINDOW *win)
{
	short	i;
	short	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mas[i][j] = 0;
	}
	add_number(mas);
	add_number(mas);
	print_numbers(win, mas);
}

void	print_numbers(WINDOW *win, int mas[4][4])
{
	short	i;
	short	j;
	int		y;
	int		x;

	i = -1;
	getmaxyx(stdscr, y, x);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			(mas[i][j]) ?
				mvwprintw(win, ((y - 5) / 4) * j + y / 8, ((x - CHAMPS_WIDTH)
							/ 4) * i + x / 8 - 5, " %4d", mas[i][j]) :
				mvwprintw(win, ((y - 5) / 4) * j + y / 8, ((x - CHAMPS_WIDTH)
							/ 4) * i + x / 8 - 5, "%5s", "");
	}
	mvwprintw(win, 0, 0, "%s", "");
	wrefresh(win);
}

short	check_number(int mas[4][4], short x, short y)
{
	short res;

	res = 1;
	if (x > 0 && mas[x - 1][y] == mas[x][y])
		res = 0;
	if (x < 3 && mas[x + 1][y] == mas[x][y])
		res = 0;
	if (y < 3 && mas[x][y + 1] == mas[x][y])
		res = 0;
	if (y > 0 && mas[x][y - 1] == mas[x][y])
		res = 0;
	return (res);
}

void	copy_numbers(int src[4][4], int dst[4][4])
{
	short i;
	short j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = src[i][j];
	}
}
