/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:23:08 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/11 15:23:29 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	x_costil_my_right(t_struct *bord)
{
	int start = 1;
	int finish = 2 * bord->nb_my_fig;
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

void	y_costil_down(t_struct *bord)
{
	int start = 0;
	int finish = 2 * bord->nb_my_fig;
	while (start < finish)
	{
		if (bord->my_cord[start] == bord->y_bord_size - 1)
		{
			bord->y_costil = 0;
			bord->best_len = 1000;
			return ;
		}
		start += 2;
	}
}

int 	ft_middle_en_y(t_struct *bord)
{
	int summ = 0;
	int start = 0;
	int res = 0;
	int finish = 2 * bord->nb_en_fig;
	while (start < finish)
	{
		summ += bord->en_cord[start];
		start += 2;
	}
	res = summ / bord->nb_en_fig;
	return (res);
}

int 	ft_middle_en_x(t_struct *bord)
{
	int summ = 0;
	int start = 1;
	int res = 0;
	int	finish = 2 * bord->nb_en_fig;
	while (start < finish)
	{
		summ += bord->en_cord[start];
		start += 2;
	}
	res = summ / bord->nb_en_fig;
	return (res);
}

void	ft_best_allocate(t_struct *bord)
{
	int b = 0;
	int by;
	int bx;
	if (bord->a == 'u')
	{
		if (bord->x_costil == 0)
			x_costil_left(bord);
		if (bord->x_costil == 1)
		{
			bx = (ft_middle_en_x(bord) - bord->res_star[bord->nb_st * 2 - 1]);
			by = (ft_middle_en_y(bord) - bord->res_star[bord->nb_st * 2 - 2]);

		}
		y_costil_down(bord);
		if ((bord->x_costil == 0) && (bord->y_costil == 1))
		{
			bx = (0 - bord->res_star[1]);
			by = ((bord->y_bord_size / 4) - bord->res_star[0]);
		}
		if ((bord->x_costil == 0) && bord->y_costil == 0)
		{
			bx = ((bord->x_bord_size) - bord->res_star[bord->nb_st * 2 - 1]);
			by = (0 - bord->res_star[bord->nb_st * 2 - 2]);
		}
		bx = bx < 0 ? bx * (-1) : bx * 1;
		by = by < 0 ? by * (-1) : by * 1;
		b = by + bx;
		if (b < bord->best_len)
		{
			bord->res_coordinates[0] = bord->res_token[0];
			bord->res_coordinates[1] = bord->res_token[1];
			bord->best_len = b;
		}
	}
	if (bord->a == 'd')
	{
		if (bord->x_costil_my_right == 0)
			x_costil_my_right(bord);
		if (bord->x_costil_my_right == 0)
		{
			bx = ((bord->x_bord_size - 1) - bord->res_star[1]);
			by = ((bord->y_bord_size / 4) - bord->res_star[0]);
		}
		if (bord->x_costil_my_right == 1)
		{
			bx = (0) - bord->res_star[1];
			by = ((bord->y_bord_size / 5) - bord->res_star[0]);
		}
		bx = bx < 0 ? bx * (-1) : bx * 1;
		by = by < 0 ? by * (-1) : by * 1;
		b = by + bx;
		if (b < bord->best_len)
		{
			bord->res_coordinates[0] = bord->res_token[0];
			bord->res_coordinates[1] = bord->res_token[1];
			bord->best_len = b;
		}
	//	}
	}
}

void	ft_find_coordinats(t_struct *bord)
{
	int index = 0;
	int count = 0;
	int tmp = 0;

	bord->a = bord->en_cord[0] > bord->my_cord[0] ? 'u' : 'd';
	while (index < bord->nb_my_fig)
	{
		while (count < bord->nb_st)
		{
			tmp = ft_change_cord(bord, count, index);
			if (tmp && ft_check_cord(bord, bord->res_token, 0, bord->y_bord_size)\
			 && ft_check_cord(bord, bord->res_token, 1, bord->x_bord_size)
			 && ft_check_en(bord) && check_double_str_my(bord)) 
			{
				ft_best_allocate(bord);
			}
			ft_memmove(bord->res_token, bord->token, sizeof(int) * 2 * bord->nb_tok);
			ft_memmove(bord->res_star, bord->star_token, sizeof(int) * 2 * bord->nb_st);
			count++;
		}
		count = 0;
		index++;
	}
}

/*
*** start program
*/

int main(void)
{
	t_struct bord;

	ft_defolt_struct(&bord);
	char *line;
	int count;
	int index = 0;
	int intok = 0;
	bord.best_len = 1000;
	bord.x_costil = 0;
	bord.y_costil = 1;
	bord.x_costil_my_right = 0;
	line = NULL;
	count = 1;
	bord.a = '\0';
	bord.my_friend_carli = '\0';

//	int flag_error = 1;
//	int fd = open("../input", O_RDONLY);
	while (get_next_line(0, &line)/* && flag_error*/)
	{
		if (ft_strstr(line, "carli"))
			bord.my_friend_carli = 'C';
		if (ft_strstr(line, "tlutsyk.filler") && ft_strstr(line, "p1"))
			bord.my_fig = 'O';
		if (ft_strstr(line, "tlutsyk.filler") && ft_strstr(line, "p2"))
			bord.my_fig = 'X';
		if (ft_strstr(line, "Plateau"))
			ft_make_str_bord(line, &bord);
		if (ft_isdigit(line[0]))
		{
			bord.m_bords[index] = ft_strdup(&line[4]);
			index++;
		}
		if (ft_strstr(line, "Piece"))
		{
			ft_make_str_token(line, &bord);
			count = bord.y_token_size;
		}
		if (CHAR_TOKEN(*line))
		{
			bord.s_token[intok] = ft_strdup(&line[0]);
			intok++;
			--count;
		}
		if (count == 0)
		{
			ft_fill_struct(&bord);
			ft_find_coordinats(&bord);
			ft_putnbr_fd(bord.res_coordinates[0], 1);
			write(1, " ", 1);
			ft_putnbr_fd(bord.res_coordinates[1], 1);
			write(1, "\n", 1);
			ft_free_str(&bord);
			ft_defolt_struct(&bord);
			count = 1;
			index = 0;
			intok = 0;
			bord.best_len = 1000;
		}
		ft_strdel(&line);
	}
	// while (1)
	// 	;
	return (0);
}
