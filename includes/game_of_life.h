/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalesev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:26:30 by dmalesev          #+#    #+#             */
/*   Updated: 2022/06/23 11:26:57 by dmalesev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	print_map(uint8_t **map, size_t line_len, size_t lines);
void	iterate_map(uint8_t **map, size_t line_len, size_t lines, int iters);

#endif
