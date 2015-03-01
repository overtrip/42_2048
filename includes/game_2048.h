/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:06:26 by jealonso          #+#    #+#             */
/*   Updated: 2015/03/01 22:32:36 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H
# include "libft.h"
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# define WIN_VALUE 2048
# define KEY_ESC 27

/*
** ft_fuse.c
*/
int		ft_fuse(int *a, int *b);

/*
**	free_tab.c
*/
void	ft_free_tab(int	**tab);

/*
** aff_win.c
*/
void	ft_aff_win(int	**tab);

/*
** create_tab.c
*/
int		**create_tab();

/*
** ft_count_z.c
*/
int		ft_count_z(int **tab);

/*
** ft_win.c
*/
int		ft_win(int **tab, WINDOW *win);

/*
** ft_fail.c
*/
int		ft_fail(int **tab, WINDOW *win);

/*
** update_right.c
*/
int		ft_m_s_r(int **tab);

/*
** update_down.c
*/
int		ft_m_s_d(int **tab);

/*
** update_up.c
*/
int		ft_m_s_u(int **tab);

/*
** update_left.c
*/
int		ft_m_s_l(int **tab);

/*
** addrandom.c
*/
void	addrandom(int **tab);

#endif
