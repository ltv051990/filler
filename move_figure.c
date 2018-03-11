/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:45:48 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/17 17:45:48 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

/*
*** write new coordinats to int array (coordinats + delta)
*/

void	change_star_cord(t_struct *bord, int start, int delta)
{
	int	finish;

	finish = 2 * bord->nb_st;
	while (start < finish)
	{
		bord->res_star[start] = bord->res_star[start] + delta;
		start += 2;
	}
}

void	change_token_cord(t_struct *bord, int start, int delta)
{
	int	finish;

	finish = 2 * bord->nb_tok;
	while (start < finish)
	{
		bord->res_token[start] = bord->res_token[start] + delta;
		start += 2;
	}
}

/*
*** change coordinats + delta
*/

int		ft_change_cord(t_struct *bord, int str_nb, int al_nb)
{
	int	str_ind;
	int	alp_ind;
	int	delta_x;
	int	delta_y;

	str_ind = str_nb * 2;
	alp_ind = al_nb * 2;
	delta_y = ft_delta_coordinates(bord->my_cord[alp_ind],
									bord->star_token[str_ind]);
	delta_x = ft_delta_coordinates(bord->my_cord[alp_ind + 1],
									bord->star_token[str_ind + 1]);
	if (delta_y < 0 || delta_x < 0)
		return (0);
	change_token_cord(bord, 0, delta_y);
	change_token_cord(bord, 1, delta_x);
	change_star_cord(bord, 0, delta_y);
	change_star_cord(bord, 1, delta_x);
	return (1);
}

/*
*** find large coordinate int token
*/

int		chec_max_size(t_struct *bord, int *tab, int start)
{
	int	yx;
	int	max;

	yx = start;
	max = tab[(bord->nb_tok * 2) - 2 + start];
	while (yx < (bord->nb_tok * 2))
	{
		if (max < tab[yx])
			max = tab[yx];
		yx = yx + 2;
	}
	return (max);
}
