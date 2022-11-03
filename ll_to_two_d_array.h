/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll_to_two_d_array.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:46:09 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/03 11:46:09 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL_TO_TWO_D_ARRAY_H
# define LL_TO_TWO_D_ARRAY_H

/* Public libraries */
# include "tokenize.h"
# include "structs.h"

char	**ll_to_two_d_array(t_map_element *map_element, char *file_str);
int		get_start_pos(char **two_d_a, unsigned int start_pos[2]);

#endif /* ll_to_two_d_array.h */