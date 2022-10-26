/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:58:34 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 12:17:20 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_INPUT_H
# define VALIDATE_INPUT_H

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

bool	is_dot_cub_file(char *arg);
bool	is_sorted(t_map_element *map_element);

#endif