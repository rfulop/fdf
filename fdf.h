/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 02:50:51 by rfulop            #+#    #+#             */
/*   Updated: 2017/05/29 22:53:07 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

#define HEIGHT 600
#define WIDTH  800

typedef struct    s_point
{
  int               x;
  int               y;
  int               z;
  int               color;
}                   t_point;

typedef struct	   	s_image
{
  void              *ptr;
  char              *data;
  int               bpp;
  int               size_line;
  int               endian;
}					          t_image;

typedef struct		  s_mlx
{
  void             *ptr;
  void             *window;
  char              *file;
  struct s_point    **point;
  int               columns;;
  int               lines;
  struct s_image   image;
  int               x;
  int               y;
  int               tmp_x;
  int               tmp_y;
}					          t_mlx;

/*
 ** Main functions
*/

/*
 ** Init functions
*/

/*
 ** Print functions
*/

/*
 ** Debug functions
*/

#endif
