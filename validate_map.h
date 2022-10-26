/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:29:51 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 17:33:13 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_MAP_H
# define VALIDATE_MAP_H

/* Public libraries */
# include <stdbool.h>

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

bool has_invalid_chars(t_map_element *map_element);
bool has_multiple_start_positions(t_map_element *map_element);
bool has_start_position(t_map_element *map_element);

#endif /* validate_map.h */
