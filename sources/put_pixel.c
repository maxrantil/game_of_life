/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalesev <dmalesev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 08:25:53 by dmalesev          #+#    #+#             */
/*   Updated: 2022/06/23 18:26:58 by dmalesev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

void	ft_clear_img(t_utils *utils)
{
	int	x;
	int	y;

	y = 0;
	while (y < utils->curr_img->dim.height)
	{
		x = 0;
		while (x < utils->curr_img->dim.width)
		{
			ft_pixel_put(x, y, 0x000000, (void *)utils->curr_img);
			x++;
		}
		y++;
	}
}

void	ft_pixel_put(int x, int y, int color, void *param)
{
	t_img	*img;
	char	*dst;

	img = param;
	if (x >= 0 && y >= 0 && x < img->dim.width && y < img->dim.height)
	{
		dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = (unsigned int)color;
	}
}
