/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:15:43 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 12:35:10 by dskrypny         ###   ########.fr       */
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
	// wclear(win);
	getmaxyx(stdscr, y, x);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			(mas[i][j]) ?
				mvwprintw(win, ((y - 5) / 4) * j + y / 8, ((x - CHAMPS_WIDTH) / 4) * i + x / 8 - 5, " %4d", mas[i][j]) :
				mvwprintw(win, ((y - 5) / 4) * j + y / 8, ((x - CHAMPS_WIDTH) / 4) * i + x / 8 - 5, "%5s", "");
	}
	mvwprintw(win, 0, 0, "%s", "");
	// wrefresh(win);
}
