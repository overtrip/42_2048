/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addrandom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:30:44 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:06:37 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	addrandom(int **tab)
{
	int	j;
	int	i;
	int	cmp;

	j = -1;
	cmp = ft_count_z(tab);
	if (cmp == 0)
		return ;
	cmp = (rand() % cmp) + 1;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			if (tab[j][i] == 0)
			{
				cmp--;
				if (cmp == 0)
					tab[j][i] = (((rand() % 2) + 1) * 2);
			}
		}
	}
}
