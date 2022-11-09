/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ll_to_a_map.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:46:09 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/09 17:11:52 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL_TO_A_MAP
# define LL_TO_A_MAP

/* Public libraries */
# include "tokenize.h"
# include "structs.h"
# include "validate_map.h"

int		get_map_size(t_map_element *map_element);
int		get_map_col_size(t_map_element *map_element);
char	**ll_to_a_map(t_map_element *map_element, char *file_str);

#endif /* ll_to_a_map.h */