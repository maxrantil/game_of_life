/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:24:07 by dmalesev          #+#    #+#             */
/*   Updated: 2022/07/04 11:38:06 by dmalesev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void	translate_pixels_to_coords(t_utils *utils, int x, int y, u_int8_t set)
{
	float	x_scale;
	float	y_scale;

	x_scale = (float)utils->line_len / (float)utils->img.dim.width;
	y_scale = (float)utils->lines / (float)utils->img.dim.height;
	x -= utils->img.dim.x0;
	y -= utils->img.dim.y0;
	x = (int)((float)x * x_scale);
	y = (int)((float)y * y_scale);
	if (utils->map[y][x] != set)
	{
		utils->map[y][x] = set;
		render_screen(utils);
	}
}

void	hold_left_button(t_utils *u, int x, int y)
{
	if (coords_in_img(&u->img, x, y))
		translate_pixels_to_coords(u, x, y, 1);
}

void	left_button_down(t_utils *u, int x, int y)
{
	if (coords_in_img(&u->img, x, y))
		translate_pixels_to_coords(u, x, y, 1);
	u->state = 0;
}

void	left_button_up(t_utils *u, int x, int y)
{
	if (coords_in_img(&u->img, x, y))
		translate_pixels_to_coords(u, x, y, 1);
	u->state = 1;
}
