/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:29:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/08 16:09:22 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_MAP_H
# define VALIDATE_MAP_H

/* Public libraries */
# include <stdbool.h>

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

bool	has_invalid_chars(t_map_element *map_element);
bool	has_multiple_start_positions(t_map_element *map_element);
bool	has_start_position(t_map_element *map_element);
int		get_map_col_size(t_map_element *map_element);
bool	has_single_start_position(t_map_element *map_element);
int		get_start_pos(char **two_d_a, unsigned int start_pos[2]);

#endif /* validate_map.h */
