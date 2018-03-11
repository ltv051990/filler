/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:49:20 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/16 20:49:20 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
/*MAP 2/3 BEST UP 100% AND sup and carli down*/
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
			bx = ((bord->x_bord_size) - bord->res_star[1]);
			by = (0 - bord->res_star[0]);
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

/////////////////////////////////////////////////////////////////////////


int 	ft_middle_my_y(t_struct *bord)
{
	int summ = 0;
	int start = 0;
	int res = 0;
	int finish = 2 * bord->nb_my_fig;
	while (start < finish)
	{
		summ += bord->my_cord[start];
		start += 2;
	}
	res = summ / bord->nb_my_fig;
	return (res);
}

int 	ft_middle_my_x(t_struct *bord)
{
	int summ = 0;
	int start = 1;
	int res = 0;
	int	finish = 2 * bord->nb_my_fig;
	while (start < finish)
	{
		summ += bord->my_cord[start];
		start += 2;
	}
	res = summ / bord->nb_my_fig;
	return (res);
}

// int 	ft_middle_my_y(t_struct *bord)
// {
// 	int summ = 0;
// 	int start = 0;
// 	int res = 0;
// 	int finish = 2 * bord->nb_my_fig;
// 	while (start < finish)
// 	{
// 		summ += bord->my_cord[start];
// 		start += 2;
// 	}
// 	res = summ / bord->nb_my_fig;
// 	return (res);
// }

// int 	ft_middle_my_x(t_struct *bord)
// {
// 	int summ = 0;
// 	int start = 1;
// 	int res = 0;
// 	int	finish = 2 * bord->nb_my_fig;
// 	while (start < finish)
// 	{
// 		summ += bord->my_cord[start];
// 		start += 2;
// 	}
// 	res = summ / bord->nb_my_fig;
// 	return (res);
// }