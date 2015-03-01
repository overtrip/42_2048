/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:10:27 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:40:25 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int	**create_tab(void)
{
	int	**tab;
	int	i;
	int j;

	i = -1;
	j = -1;
	tab = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4)
		tab[i] = (int *)malloc(sizeof(int) * 4);
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			tab[j][i] = 0;
		}
	}
	addrandom(tab);
	addrandom(tab);
	return (tab);
}
