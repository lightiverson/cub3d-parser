/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:00:46 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/25 12:22:43 by kgajadie      ########   odam.nl         */
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
# include "../utils.h"

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
int				get_map_fd(const char *map_name);
int				file_to_str(int fd, char **file_str);

/* tokenize.c */
t_map_element	*tokenizer(char *file_str);

#endif /* tokenize.h */
