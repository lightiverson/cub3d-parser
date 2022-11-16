/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:07:43 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 19:01:52 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>

typedef struct s_map_element {
	char					*map_element;
	int						type;
	struct s_map_element	*next;
}	t_map_element;

typedef struct s_stack {
	int				cr;
	int				cc;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data {
	bool	has_no;
	bool	has_so;
	bool	has_we;
	bool	has_ea;
}	t_data;

#endif
