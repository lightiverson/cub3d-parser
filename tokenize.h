/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:00:46 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/03 11:46:37 by kgajadie      ########   odam.nl         */
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

bool			is_dot_cub_file(char *arg);
void			free_map_elements(t_map_element *head);
void			print_map_elements(t_map_element *head);
t_map_element	*tokenizer(char *file_str);
bool			is_sorted(t_map_element *map_element);
bool			has_two_valid_strs(t_map_element *map_element);

#endif /* tokenize.h */
