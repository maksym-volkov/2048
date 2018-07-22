/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:57:26 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 21:00:48 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		end_game(int numbers[4][4], t_result *res)
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
	if (max == WIN_VALUE && !res->won)
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
	if ((end = end_game(numbers, res)))
		return (end);
	return (1);
}

static int		print_info(short c, t_result *res)
{
	int		key;

	mvwprintw(res->win[1], 1, 1, "%55s", "");
	if (c == 1)
		mvwprintw(res->win[1], 1, 3, "Goodbye, press any key to exit");
	else if (c == 3)
		mvwprintw(res->win[1], 1, 3,
				"You lost! Press R to replay or ESC to exit");
	else if (c == 2)
	{
		mvwprintw(res->win[1], 1, 3,
				"Well done! Press R to replay or any key to continue");
		res->won = 1;
	}
	wrefresh(res->win[1]);
	keypad(res->win[1], 1);
	key = wgetch(res->win[1]);
	if ((c == 1) || (c == 3 && key == 27) || (c == 2 && key != 114))
		return ((c == 1) ? 27 : key);
	while (key != 114)
		key = wgetch(res->win[1]);
	create_numbers(res);
	return (key);
}

static void		doing(t_result res)
{
	int			reserve[4][4];
	int			key;
	short		c;

	c = 1;
	res.won = 0;
	res.result = 0;
	create_numbers(&res);
	print_result(&res);
	keypad(res.win[0], 1);
	while ((key = wgetch(res.win[0])) != 27)
	{
		draw_map(res.win[0]);
		update_map(res.win[1], res.win[2]);
		print_numbers(res.win[0], res.numbers);
		print_result(&res);
		if ((c = hook_keys(key, &res, res.numbers, reserve)) != 1)
			key = print_info(c, &res);
		if (key == 27)
			break ;
	}
	print_info(1, &res);
}

int				main(void)
{
	t_result	res;
	short		c;

	if (WIN_VALUE < 0 || WIN_VALUE > 16384 || !power_of_two(WIN_VALUE))
		ft_error("Invalided number\n");
	res.name = read_name();
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
