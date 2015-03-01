/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:29:30 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:11:31 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		fail_msg(WINDOW *win)
{
	int	x;
	int y;

	getmaxyx(win, y, x);
	wmove(win, (y / 2), (x / 2));
	wprintw(win, "Die monkey");
	wrefresh(win);
}

int				ft_fail(int **tab, WINDOW *win)
{
	int	**copy;
	int	j;
	int	i;

	j = -1;
	copy = create_tab();
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			copy[j][i] = tab[j][i];
	}
	if (!(ft_m_s_r(copy) || ft_m_s_d(copy) || ft_m_s_u(copy) || ft_m_s_l(copy)))
	{
		fail_msg(win);
		ft_free_tab(copy);
		while ((i = wgetch(win)) != KEY_ESC)
			;
		return (1);
	}
	ft_free_tab(copy);
	return (0);
}
