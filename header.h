/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 09:58:12 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 12:38:28 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <ncurses.h>
# include <time.h>

# define END_GAME 2048
# define INFO_HEIGHT 4
# define CHAMPS_WIDTH 30

typedef struct	s_point
{
	short		x;
	short		y;
}				t_point;

typedef struct	s_window
{
	short		heigth;
	short		width;
	t_point		start_win;
}				t_window;

void			add_number(int mas[4][4]);
void			create_numbers(int mas[4][4], WINDOW *win);
void			print_numbers(WINDOW *win, int mas[4][4]);

void			init_help(WINDOW **win_info, WINDOW **win_champs);
void			init_window(t_window *win_prop, WINDOW **win);

short			move_up(int mas[4][4]);
short			move_down(int mas[4][4]);
short			move_left(int mas[4][4]);
short			move_right(int mas[4][4]);

void			drow_map(WINDOW *win);

#endif
