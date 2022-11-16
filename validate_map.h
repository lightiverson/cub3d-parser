/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:29:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 18:48:30 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_MAP_H
# define VALIDATE_MAP_H

/* Public libraries */
# include <stdbool.h>

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

/* validate_map.c */
bool	has_invalid_chars(t_map_element *map_element);
bool	has_single_start_position(t_map_element *map_element);
bool	has_three_map_elements_min(t_map_element *map_element);

/* floodfill.c */
int		get_start_pos(char **two_d_a, unsigned int start_pos[2]);
bool	itter_floodfill(char *map[], unsigned int pos[2], int rows, int cols);

#endif /* validate_map.h */
