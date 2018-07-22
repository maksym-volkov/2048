/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:05:01 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/22 20:46:11 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_result(t_result *res)
{
	int		i;

	mvwprintw(res->win[1], 1, 1, "%55s", "");
	wrefresh(res->win[1]);
	mvwprintw(res->win[2], 1, 2, "%20s", "");
	mvwprintw(res->win[2], 1, 2, "Your result is: %d", res->result);
	mvwprintw(res->win[2], 2, 2, "Champions:");
	i = -1;
	while (res->log[++i])
		mvwprintw(res->win[2], 3 + i, 3, "%s", res->log[i]);
	wrefresh(res->win[2]);
}

char	**reader(void)
{
	short	fd;
	char	**res;

	fd = open("log", O_RDONLY);
	res = ft_strsplit("111\n222\n333", '\n');
	return (res);
}
