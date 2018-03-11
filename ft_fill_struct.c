/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:06:30 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/13 14:06:32 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		ft_delta_coordinates(int xy1, int xy2)
{
	return (xy1 - xy2);
}

void	ft_write_token_cord_to_int(char **find, int **tab)
{
	int x;
	int y;
	int it;

	it = 0;
	y = 0;
	while (find[y])
	{
		x = 0;
		while (find[y][x])
		{
			if (find[y][x] == '.' || find[y][x] == '*')
			{
				(*tab)[it++] = y;
				(*tab)[it++] = x;
			}
			x++;
		}
		y++;
	}
}

void	ft_write_cord_to_int(char alpha, char **find, int **tab)
{
	int x;
	int y;
	int it;
	char alpha2;

	it = 0;
	alpha2 = '*';
	if (ft_isalpha(alpha))
		alpha2 = alpha + 32;
	y = 0;
	while (find[y])
	{
		x = 0;
		while (find[y][x])
		{
			if (find[y][x] == alpha || find[y][x] == alpha2)
			{
				(*tab)[it++] = y;
				(*tab)[it++] = x;
			}
			x++;
		}
		y++;
	}
}

void	ft_fill_struct(t_struct *bord)
{
	bord->en_fig = bord->my_fig == 'O' ? 'X' : 'O';
	bord->nb_my_fig = ft_st_search_cord(bord->m_bords, bord->my_fig, bord->my_fig + 32);
	bord->nb_en_fig = ft_st_search_cord(bord->m_bords, bord->en_fig, bord->en_fig + 32);
	bord->nb_st = ft_st_search_cord(bord->s_token, '*', '*');
	bord->nb_tok = ft_st_search_cord(bord->s_token, '*', '.');
	bord->my_cord = (int *)malloc(sizeof(int) * bord->nb_my_fig * 2);
	bord->en_cord = (int *)malloc(sizeof(int) * bord->nb_en_fig * 2);
	bord->token = (int *)malloc(sizeof(int) * (bord->nb_tok * 2));
	bord->res_token = (int *)malloc(sizeof(int) * (bord->nb_tok * 2));
	bord->star_token = (int *)malloc(sizeof(int) * (bord->nb_st) * 2);
	bord->res_star = (int *)malloc(sizeof(int) * (bord->nb_st) * 2);
	ft_write_cord_to_int(bord->my_fig, bord->m_bords, &(bord->my_cord));
	ft_write_cord_to_int(bord->en_fig, bord->m_bords, &(bord->en_cord));
	ft_write_cord_to_int('*', bord->s_token, &(bord->star_token));
	ft_write_token_cord_to_int(bord->s_token, &(bord->token));
	ft_memmove(bord->res_token, bord->token, sizeof(int) * (2 * bord->nb_tok));
	ft_memmove(bord->res_star, bord->star_token, sizeof(int) * (2 * bord->nb_st));
}

void	x_costil_left(t_struct *bord)
{
	int start = 1;
	int finish = 2 * bord->nb_my_fig;
	while (start < finish)
	{
		if (bord->my_cord[start] == 0)
		{
			bord->x_costil = 1;
			bord->best_len = 1000;
			return ;
		}
		start += 2;
	}
}