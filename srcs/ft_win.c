/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:30:04 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:12:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		ft_win(int **tab, WINDOW *win)
{
	int	j;
	int	i;
	int	x;
	int	y;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (tab[j][i] == WIN_VALUE)
			{
				getmaxyx(win, y, x);
				wmove(win, (y / 2), (x / 2));
				wprintw(win, "encore une victoire de canard");
				wrefresh(win);
				while ((i = wgetch(win)) != KEY_ESC)
					;
				return (1);
			}
		}
	}
	return (0);
}
