/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:00:46 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/12/06 14:05:12 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

/* Public libraries */
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>

/* Private libraries */
# include "../structs.h"
# include "../libft/libft.h"
# include "../utils/utils.h"

enum e_element_type {
	E_CARDINAL = 1,
	E_FLOOR_CEILING,
	E_MAP
};

enum e_sub_type {
	SUB_NO = 1,
	SUB_SO,
	SUB_WE,
	SUB_EA,
	SUB_FLOOR,
	SUB_CEILING,
};

/* file_to_str.c */
bool	is_directory(const char *map_name);
int		get_map_fd(const char *map_name);
int		file_to_str(int fd, char **file_str);

/* tokenize.c */
void	inner_tokenizer(char *split_a_i, t_map_element **map_elements);

#endif /* tokenize.h */
