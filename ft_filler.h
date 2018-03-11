/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:24:14 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/01/12 12:24:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include "get_next_line.h"
# include <stdio.h> // DELETE
# include <fcntl.h> // DELETE

# define  CHAR_TOKEN(u) (u == '.' || u == '*')

typedef struct	s_struct
{
	char		**m_bords; // str bord wirh figure
	char		**s_token;	// str key
	char		my_fig;		// char my alpha
	char		en_fig;     // char enemy alpha
	int			y_bord_size;  // nb of lines in bord
	int			x_bord_size; //nb of colums in bord
	int			y_token_size; // nb of lines in token
	int			x_token_size; //nb of colums in token
///////////////////////////////////////////////////////////
	int			*my_cord;	// мої координати
	int			*en_cord;	// ворожі координати
///////////////////////////////////////////////////////////
	int			*token;		// шаблон координат токена
	int			*res_token;	// координати ключа для руху
///////////////////////////////////////////////////////////
	int			*res_star;	//резервний масив зірок для руху
	int			*star_token;	// масив зірок для шаблону
///////////////////////////////////////////////////////////
	int 		res_coordinates[2]; // return (res)
	int			nb_my_fig; //count all o 
	int			nb_en_fig; //count all x
	int			nb_tok; //
	int			nb_st; //count all *
///////////////////////////////////////////////////////////
	int index;
 	int intok;
	int 		best_len; // best cord to return
	char 		a; // my position
	int 		x_costil; //left
	int 		y_costil; // down
	int			x_costil_middle; // miidle of the map
	int 		x_costil_my_right; // 
	int 		y_costil_en_down; // right
	int 		x_costil_en_middle; //
	int 		y_costil_up_my;
	char		my_friend_carli;
	/*
	bord.x_costil_my_right = 0;
	bord.y_costil_en_down = 0;
	bord.x_costil_en_middle = 0;
	*/
	///////////////////////////////////////////////////////////
}				t_struct;

/*
*** start read struct
*/

void			ft_make_str_bord(char *line, t_struct *bord);
void			ft_make_str_token(char *line, t_struct *bord);
int				ft_delta_coordinates(int xy1, int xy2);
void			ft_fill_struct(t_struct *bord);
void			ft_start_read(t_struct *bord);
void			ft_make_str_bord(char *line, t_struct *bord);
int				ft_st_search_cord(char **find, char alpha1, char alpha2);
void			ft_fill_struct(t_struct *bord);
void			change_token_cord(t_struct *bord, int start, int delta);
int				ft_change_cord(t_struct *bord, int str_nb, int al_nb);
int				chec_max_size(t_struct *bord, int *tab, int start);
int				ft_find_cord(t_struct *bord);
void		 	ft_defolt_struct(t_struct *bord);
void			ft_free_str(t_struct *bord);
void			ft_best_allocate(t_struct *bord);
void			ft_find_coordinats(t_struct *bord);
int 			ft_check_cord(t_struct *bord, int *tab, int start, int map_size);
int 			check_double_str_my(t_struct *bord);
int				ft_check_en(t_struct *bord);
void			change_star_cord(t_struct *bord, int start, int delta);
void	x_costil_left(t_struct *bord);
void	x_costil_right(t_struct *bord);
void	y_costil_down(t_struct *bord);

/*
*** start read struct
*/

#endif