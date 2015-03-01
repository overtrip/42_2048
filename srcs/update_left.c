/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:24:34 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:29:52 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		ft_slide_l(int **tab, int j)
{
	int	i;
	int k;
	int val;

	val = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			k = i;
			while (++k < 4 && tab[i][j] == 0)
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

static int		ft_mov_l(int **tab, int j)
{
	int	i;
	int k;
	int val;

	val = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			k = i;
			while (++k < 4 && tab[i][j] != 0)
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

int				ft_m_s_l(int **tab)
{
	if (ft_mov_l(tab, -1) + ft_slide_l(tab, -1) > 0)
	{
		addrandom(tab);
		return (1);
	}
	return (0);
}
