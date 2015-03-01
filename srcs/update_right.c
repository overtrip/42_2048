/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:22:39 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:30:08 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		ft_mov_r(int **tab, int j)
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
			while (--k >= 0 && tab[i][j] != 0)
			{
				if (tab[k][j] == tab[i][j])
				{
					val = ft_fuse(&tab[i][j], &tab[k][j]);
					break ;
				}
				if (tab[k][j] != 0)
					break ;
			}
		}
	}
	return (val);
}

static int		ft_slide_r(int **tab, int j)
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
			while (--k >= 0 && tab[i][j] == 0)
			{
				if (tab[k][j] != 0)
				{
					val = 1;
					tab[i][j] = tab[k][j];
					tab[k][j] = 0;
					break ;
				}
			}
		}
	}
	return (val);
}

int				ft_m_s_r(int **tab)
{
	if (ft_mov_r(tab, -1) + ft_slide_r(tab, -1) > 0)
	{
		addrandom(tab);
		return (1);
	}
	return (0);
}
