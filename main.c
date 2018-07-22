/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 18:26:51 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		end_game(int numbers[4][4])
{
	short			i;
	short			j;
	short			count;
	short			max;

	count = 0;
	max = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (numbers[i][j] != 0)
				count += check_number(numbers, i, j);
			if (numbers[i][j] > max)
				max = numbers[i][j];
		}
	}
	if (count == 16)
		return (3);
	if (max == WIN_VALUE)
		return (2);
	return (0);
}

static int		hook_keys(int key, t_result *res, int numbers[4][4],
		int reserve[4][4])
{
	int		result;
	short	end;

	result = 1;
	if (key == KEY_UP)
		result = move_up(numbers, res);
	else if (key == KEY_DOWN)
		result = move_down(numbers, res);
	else if (key == KEY_LEFT)
		result = move_left(numbers, res);
	else if (key == KEY_RIGHT)
		result = move_right(numbers, res);
	else if (key == 117)
		copy_numbers(reserve, numbers);
	else
		return (1);
	if (result && key != 117)
		add_number(numbers);
	print_numbers(res->win[0], numbers);
	if ((end = end_game(numbers)))
		return (end);
	return (1);
}

static int		print_info(short c, t_result *res)
{
	int	key;

	if (c == 3)
		mvwprintw(res->win[1], 1, 3, "Game Over");
	if (c == 2 && !res->won)
	{
		mvwprintw(res->win[1], 1, 3, "Well done!");
		res->won = 1;
	}
	if (c == 1)
		mvwprintw(res->win[1], 1, 3, "Goodbye");
	wrefresh(res->win[1]);
	if (c == 1)
		return (0);
	keypad(res->win[1], 1);
	key = wgetch(res->win[1]);
	while (key != 27 && key != 114)
		key = wgetch(res->win[1]);
	return (key);
}

static void		doing(t_result res)
{
	int			numbers[4][4];
	int			reserve[4][4];
	int			key;
	short		c;

	res.won = 0;
	res.result = 0;
	create_numbers(numbers, res.win[0]);
	keypad(res.win[0], 1);
	print_result(&res);
	while ((key = wgetch(res.win[0])) != 27)
	{
		draw_map(res.win[0]);
		update_map(res.win[1], res.win[2]);
		print_numbers(res.win[0], numbers);
		print_result(&res);
		if ((c = hook_keys(key, &res, numbers, reserve)) != 1)
			break ;
	}
	key = print_info(c, &res);
	if (key == 114)
		doing(res);
}

int				main(void)
{
	t_result	res;
	short		c;

	initscr();
	cbreak();
	noecho();
	c = -1;
	while (++c < 3)
		res.win[c] = NULL;
	res.log = reader();
	init_window(&res.win[0], &res.win[1], &res.win[2]);
	draw_map(res.win[0]);
	doing(res);
	endwin();
	system("leaks game_2048");
	return (0);
}
