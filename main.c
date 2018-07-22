/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 12:38:27 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		end_game(int numbers[4][4])
{
	short i;
	short j;
	short count;
	short max;

	count = 0;
	max = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (numbers[i][j] != 0)
				count++;
			if (numbers[i][j] > max)
				max = numbers[i][j];
		}
	}
	if (count == 16)
		return (1);
	if (max == END_GAME)
		return (2);
	return (0);
}

static int		hook_keys(int key, WINDOW *win, int numbers[4][4])
{
	short	res;

	res = 1;
	if (end_game(numbers))
		return (0);
	if (key == KEY_UP)
		res = move_up(numbers);
	else if (key == KEY_DOWN)
		res = move_down(numbers);
	else if (key == KEY_LEFT)
		res = move_left(numbers);
	else if (key == KEY_RIGHT)
		res = move_right(numbers);
	else
		return (1);
	if (res)
		add_number(numbers);
	print_numbers(win, numbers);
	return (1);
}

void			print_info(short c, WINDOW *win_info)
{
	if (c == 0)
		mvwprintw(win_info, 1, 5, "Game Over");
	if (c == 1)
		mvwprintw(win_info, 1, 5, "Goodbye");
	wrefresh(win_info);
}

void			update_help(WINDOW *win_info, WINDOW *win_champs)
{
	int x;
	int y;

	wclear(win_info);
	wclear(win_champs);
	getmaxyx(stdscr, y, x);
	wresize(win_info, INFO_HEIGHT, x - 1);
	wresize(win_champs, y - INFO_HEIGHT, CHAMPS_WIDTH);
	box(win_info, 0, 0);
	box(win_champs, 0, 0);
	wrefresh(win_info);
	wrefresh(win_champs);
}

int				main(void)
{
	WINDOW		*win;
	WINDOW		*win_info;
	WINDOW		*win_champs;
	t_window	win_prop;
	int			numbers[4][4];
	int			key;
	short		c;

	initscr();
	cbreak();
	noecho();
	win = NULL;
	win_info = NULL;
	win_champs = NULL;
	init_window(&win_prop, &win);
	init_help(&win_info, &win_champs);
	drow_map(win);
	create_numbers(numbers, win);
	keypad(win, 1);
	while ((key = wgetch(win)) != 27)
	{
		drow_map(win);
		update_help(win_info, win_champs);
		print_numbers(win, numbers);
		if (!(c = hook_keys(key, win, numbers)))
			break ;
	}
	// print_info(c, win_info);
	wgetch(win);
	endwin();
	system("leaks game_2048");
	return (0);
}
