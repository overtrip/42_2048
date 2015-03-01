/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:34:02 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:08:43 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		ft_print_nb(WINDOW *win, int **tab)
{
	int	i;
	int	j;
	int	x;
	int y;

	j = -1;
	getmaxyx(win, y, x);
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (tab[j][i] != 0)
			{
				wmove(win, (y / 4) * i + (y / 12), (x / 4) * j + (x / 12));
				wprintw(win, "%d", tab[j][i]);
			}
		}
	}
}

static int		ft_draw_win(WINDOW *win, int **tab)
{
	int	x;
	int	y;
	int i;

	i = 0;
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	getmaxyx(win, y, x);
	if (x < 9 || y < 9)
		return (0);
	while (++i < 4)
	{
		wmove(win, (y / 4) * i, 1);
		whline(win, '-', x - 2);
		wmove(win, 1, (x / 4) * i);
		wvline(win, '|', y - 2);
		wrefresh(win);
	}
	ft_print_nb(win, tab);
	wrefresh(win);
	return (1);
}

static int		ft_control(WINDOW *win, int **tab)
{
	int	ch;

	if (ft_win(tab, win) || (ft_count_z(tab) == 0 && ft_fail(tab, win)))
		return (1);
	if ((ch = wgetch(win)) == KEY_UP)
		ft_m_s_u(tab);
	else if (ch == KEY_DOWN)
		ft_m_s_d(tab);
	else if (ch == KEY_LEFT)
		ft_m_s_l(tab);
	else if (ch == KEY_RIGHT)
		ft_m_s_r(tab);
	else if (ch == KEY_ESC)
		return (1);
	return (0);
}

void			ft_aff_win(int **tab)
{
	WINDOW *win;

	initscr();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	win = newwin(0, 0, 0, 0);
	keypad(win, TRUE);
	while ("meurt le singe")
	{
		if (ft_draw_win(win, tab) == 0)
			break ;
		if (ft_control(win, tab))
		{
			endwin();
			break ;
		}
		werase(win);
	}
	ft_free_tab(tab);
	delwin(win);
	endwin();
}
