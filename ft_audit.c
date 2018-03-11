/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_audit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:24:05 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/13 19:24:06 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	ft_free_str(t_struct *bord)
{
	int	a;

	a = -1;
	free(bord->my_cord);
	free(bord->en_cord);
	free(bord->token);
	free(bord->res_token);
	free(bord->star_token);
	free(bord->res_star);
	while (++a <= bord->y_bord_size)
	{
		free(bord->m_bords[a]);
	}
	free(bord->m_bords);
	a = -1;
	while (++a <= bord->y_token_size)
		free(bord->s_token[a]);
	free(bord->s_token);
}

void	ft_defolt_struct(t_struct *bord)
{
	ft_bzero(bord->res_coordinates, sizeof(int) * 2);
	bord->m_bords = NULL;
	bord->s_token = NULL;
	bord->y_bord_size = 0;
	bord->x_bord_size = 0;
	bord->y_token_size = 0;
	bord->x_token_size = 0;
	bord->my_cord = NULL;
	bord->en_cord = NULL;
	bord->token = NULL;
	bord->res_token = NULL;
	bord->res_star = NULL;
	bord->star_token = NULL;
	bord->nb_my_fig = 0;
	bord->nb_en_fig = 0;
	bord->nb_tok = 0;
	bord->nb_st = 0;
}

int		ft_check_en(t_struct *bord)
{
	int	first;
	int	last;
	int	res;

	res = 1;
	first = 0;
	while (first <= (bord->nb_st * 2) - 2)
	{
		last = 0;
		while (last <= (bord->nb_en_fig * 2) - 2)
		{
			if (bord->res_star[first] == bord->en_cord[last]
				&& bord->res_star[first + 1] == bord->en_cord[last + 1])
				res = 0;
			last += 2;
		}
		first += 2;
	}
	return (res);
}

int		check_double_str_my(t_struct *bord)
{
	int	first;
	int	last;
	int	count;

	first = 0;
	count = 0;
	while (first <= (bord->nb_st * 2) - 2)
	{
		last = 0;
		while (last <= (bord->nb_my_fig * 2) - 2)
		{
			if (bord->res_star[first] == bord->my_cord[last]
				&& bord->res_star[first + 1] == bord->my_cord[last + 1])
				count++;
			last += 2;
		}
		first += 2;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		ft_check_cord(t_struct *bord, int *tab, int start, int map_size)
{
	int len;

	len = chec_max_size(bord, bord->res_token, start);
	if (len >= map_size)
		return (0);
	return (1);
}
