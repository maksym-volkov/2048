/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <mvolkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:02:54 by mvolkov           #+#    #+#             */
/*   Updated: 2018/01/11 11:32:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_lines(WINDOW *win, int y, int x, int count)
{
	while (count < (x - 1))
	{
		mvwprintw(win, 0, count, "-");
		mvwprintw(win, (y - 5) / 4, count, "-");
		mvwprintw(win, ((y - 5) / 4) * 2, count, "-");
		mvwprintw(win, ((y - 5) / 4) * 3, count, "-");
		mvwprintw(win, y - 5, count, "-");
		count++;
	}
}

void	print_rows(WINDOW *win, int y, int x, int count)
{
	while (count < (y - 1))
	{
		mvwprintw(win, count, 0, "|");
		mvwprintw(win, count, (x - 20) / 4, "|");
		mvwprintw(win, count, ((x - 20) / 4) * 2, "|");
		mvwprintw(win, count, ((x - 20) / 4) * 3, "|");
		mvwprintw(win, count, x - 21, "|");
		count++;
	}
}

void	drow_map(WINDOW *win)
{
	int x;
	int y;
	int count;

	// getmaxyx(win, y, x);
	getmaxyx(stdscr, y, x);
	if (y < 10 || x < 33)
	{
		// TOO SMALL WINDOW
	}
	count = 0;
	print_lines(win, y, x, count);
	count = 0;
	print_rows(win, y, x, count);
}
