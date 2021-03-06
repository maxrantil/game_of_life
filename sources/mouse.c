/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalesev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:49:27 by dmalesev          #+#    #+#             */
/*   Updated: 2022/07/04 16:05:32 by dmalesev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

int	mouse_move(int x, int y, void *param)
{
	t_utils	*u;

	u = param;
	u->mouse.move_x = x - u->mouse.x;
	u->mouse.move_y = y - u->mouse.y;
	if ((u->mouse.button & RIGHT_BUTTON) == RIGHT_BUTTON)
	{
		hold_right_button(u, x, y);
		right_button_down(u, x, y);
	}
	if ((u->mouse.button & 1) == 1)
	{
		hold_left_button(u, x, y);
		left_button_down(u, x, y);
	}
	u->mouse.x = x;
	u->mouse.y = y;
	return (0);
}

int	mouse_up(int button, int x, int y, void *param)
{
	t_utils	*utils;

	utils = param;
	button = int_to_bit(button);
	if ((utils->mouse.button & LEFT_BUTTON) == LEFT_BUTTON)
		left_button_up(utils, x, y);
	if ((utils->mouse.button & RIGHT_BUTTON) == RIGHT_BUTTON)
		right_button_up(utils, x, y);
	if (button < 8)
		utils->mouse.button -= button;
	utils->mouse.x = x;
	utils->mouse.y = y;
	return (0);
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_utils	*utils;

	utils = param;
	button = int_to_bit(button);
	if ((button & 8) == 8 || (button & 16) == 16)
		scroll_wheel(utils, x, y);
	if ((button & 8) == 8)
		scroll_wheel_up(utils, x, y);
	if ((button & 16) == 16)
		scroll_wheel_down(utils, x, y);
	if ((button & LEFT_BUTTON) == LEFT_BUTTON)
		left_button_down(utils, x, y);
	if ((button & RIGHT_BUTTON) == RIGHT_BUTTON)
		right_button_down(utils, x, y);
	if (button < 8)
		utils->mouse.button += button;
	utils->mouse.x = x;
	utils->mouse.y = y;
	return (0);
}
