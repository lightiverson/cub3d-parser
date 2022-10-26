/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:07:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/26 12:07:38 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

void	print_map_elements(t_map_element *head);
void	print_splitted_a(char **split_a);
void	free_splitted_array(char **splitted_array);
void	free_map_elements(t_map_element *head);

#endif
