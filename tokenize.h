/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:00:46 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/09 12:57:27 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

/* Private libraries */
# include "structs.h"
# include "libft/libft.h"
# include "utils.h"

enum e_element_types {
	E_CARDINAL = 1,
	E_FLOOR_CEILING,
	E_MAP
};

/* tokenize.c */
t_map_element	*tokenizer(char *file_str);

/* validate_input.c */
bool			is_dot_cub_file(char *arg);
bool			is_sorted(t_map_element *map_element);

/* validate_non_map_elements.c */
bool			has_four_cardinals(t_map_element *map_element);
bool			has_two_fcs(t_map_element *map_element);
bool			has_four_unique_cardinals(t_map_element *map_element);
bool			has_two_unique_fcs(t_map_element *map_element);

#endif /* tokenize.h */
