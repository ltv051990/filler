/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:26:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/12 15:26:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

/*
*** malloc **bords;
*/

void	ft_make_str_bord(char *line, t_struct *bord)
{
	while (!(ft_isdigit(*line)))
		line++;
	bord->y_bord_size = ft_atoi(line);
	bord->m_bords = (char **)malloc(sizeof(char *) * (bord->y_bord_size + 1));
	bord->m_bords[bord->y_bord_size] = NULL;
	while (ft_isdigit(*line))
		line++;
	while (!(ft_isdigit(*line)))
		line++;
	bord->x_bord_size = ft_atoi(line);
}

/*
*** malloc **token;
*/

void	ft_make_str_token(char *line, t_struct *bord)
{
	while (!(ft_isdigit(*line)))
		line++;
	bord->y_token_size = ft_atoi(line);
	bord->s_token = (char **)malloc(sizeof(char *) * (bord->y_token_size + 1));
	bord->s_token[bord->y_token_size] = NULL;
	while (ft_isdigit(*line))
		line++;
	while (!(ft_isdigit(*line)))
		line++;
	bord->x_token_size = ft_atoi(line);
}

int		ft_st_search_cord(char **find, char alpha1, char alpha2)
{
	int x;
	int y;
	int res;

	y = 0;
	res = 0;
	while (find[y])
	{
		x = 0;
		while (find[y][x])
		{
			if (find[y][x] == alpha1 || find[y][x] == alpha2)
				res++;
			x++;
		}
		y++;
	}
	return (res);
}

// void	x_costil_left(t_struct *bord)
// {
// 	int start;
// 	int finish;

// 	start = 1;
// 	finish = 2 * bord->nb_my_fig;
// 	while (start < finish)
// 	{
// 		if (bord->my_cord[start] == 0)
// 		{
// 			bord->x_costil = 1;
// 			bord->best_len = 1000;
// 			return ;
// 		}
// 		start += 2;
// 	}
// }

void	x_costil_right(t_struct *bord)
{
	int start;
	int finish;

	start = 1;
	finish = 2 * bord->nb_my_fig;
	while (start < finish)
	{
		if (bord->my_cord[start] == bord->x_bord_size - 1)
		{
			bord->x_costil_my_right = 1;
			bord->best_len = 1000;
			return ;
		}
		start += 2;
	}
}
