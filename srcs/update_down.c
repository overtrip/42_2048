/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:20:27 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:24:34 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		ft_mov_d(int **tab, int j)
{
	int	i;
	int k;
	int val;

	val = 0;
	while (++j < 4)
	{
		i = 4;
		while (--i >= 0)
		{
			k = i;
			while (--k >= 0 && tab[j][i] != 0)
			{
				if (tab[j][k] == tab[j][i])
				{
					val = ft_fuse(&tab[j][i], &tab[j][k]);
					break ;
				}
				if (tab[j][k] != 0)
					break ;
			}
		}
	}
	return (val);
}

static int		ft_slide_d(int **tab, int j)
{
	int	i;
	int k;
	int val;

	val = 0;
	while (++j < 4)
	{
		i = 4;
		while (--i >= 0)
		{
			k = i;
			while (--k >= 0 && tab[j][i] == 0)
			{
				if (tab[j][k] != 0)
				{
					val = 1;
					tab[j][i] = tab[j][k];
					tab[j][k] = 0;
					break ;
				}
			}
		}
	}
	return (val);
}

int				ft_m_s_d(int **tab)
{
	if (ft_mov_d(tab, -1) + ft_slide_d(tab, -1) > 0)
	{
		addrandom(tab);
		return (1);
	}
	return (0);
}
