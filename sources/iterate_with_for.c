/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_with_for.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaavist <ahaavist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:19:07 by dmalesev          #+#    #+#             */
/*   Updated: 2022/06/23 15:32:08 by ahaavist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_of_life.h"

static void	next_free_neighbor(uint8_t *nbr)
{
	uint8_t	bit;

	if ((*nbr & 30) == 30)
		return ;
	bit = 2;
	while ((*nbr & bit) == bit)
		bit <<= 1;
	*nbr |= bit;
}

static void	add_neighbors(uint8_t **map, size_t line_len, size_t lines)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < line_len)
		{
			if ((map[i][j] & 1) == 1)
			{
				if (i > 0 && j > 0)
					next_free_neighbor(&map[i - 1][j - 1]);
				if (i > 0)
					next_free_neighbor(&map[i - 1][j]);
				if (i > 0 && j < line_len - 1)
					next_free_neighbor(&map[i - 1][j + 1]);
				if (j > 0)
					next_free_neighbor(&map[i][j - 1]);
				if (j < line_len - 1)
					next_free_neighbor(&map[i][j + 1]);
				if (i < lines - 1 && j > 0)
					next_free_neighbor(&map[i + 1][j - 1]);
				if (i < lines - 1)
					next_free_neighbor(&map[i + 1][j]);
				if (i < lines - 1 && j < line_len - 1)
					next_free_neighbor(&map[i + 1][j + 1]);
			}
			j++;
		}
		i++;
	}
}

static int	next_cycle(uint8_t **map, size_t line_len, size_t lines)
{
	int		static_check;
	size_t	i;
	size_t	j;

	static_check = 1;
	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < line_len; j++)
		{
			if ((map[i][j] & 254) == 14 || (map[i][j] & 255) == 7)
			{
				if (map[i][j] % 2 == 0)
					static_check = 0;
				map[i][j] = 1;
			}
			else
			{
				if (map[i][j] % 2 == 1)
					static_check = 0;
				map[i][j] = 0;
			}
		}
	}
	return (static_check);
}

void	iterate_map(uint8_t **map, size_t line_len, size_t lines, long iters)
{
	long	i;

	i = 0;
	while (i < iters)
	{
		add_neighbors(map, line_len, lines);
		if (next_cycle(map, line_len, lines) == 1)
			i = iters;
		i++;
	}
}
