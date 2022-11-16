/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:07:36 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 19:05:04 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Private libraries */
# include "structs.h"
# include "tokenize.h"

/* utils.c */
void	print_map_elements(t_map_element *head);
void	print_splitted_a(char **split_a);
void	print_exit(char *msg);
void	init_data(t_data *data);
void	helper_cardinals(char *first_part, t_data *data);

/* free_breezy.c */
void	free_map_elements(t_map_element *head);
void	free_splitted_array(char **splitted_array);
void	free_stack(t_stack *stack);

#endif
