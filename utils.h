/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:07:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/25 14:50:42 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Private libraries */
# include "structs.h"
# include "tokenize/tokenize.h"

/* utils.c */
void	print_map_elements(t_map_element *head);
void	print_splitted_a(char **split_a);
void	print_exit(char *msg);
void	print_rgb(t_rgb *rgb);
void	init_has_c(t_has_c *data);
int		count_ptrs(char **splitted_array);
void	print_cub(t_cub *cub);

/* free_breezy.c */
void	free_map_elements(t_map_element *head);
void	free_splitted_array(char **splitted_array);
void	free_stack(t_stack *stack);

#endif
