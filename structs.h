/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:07:43 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/22 17:33:04 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/* Public libraries */
# include <stdbool.h>

typedef struct s_data
{
	const char	*s;
	long		acc;
	long		cutoff;
	int			c;
	int			neg;
	int			any;
	int			cutlim;
}	t_data;

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

typedef struct s_has_c {
	bool	has_no;
	bool	has_so;
	bool	has_we;
	bool	has_ea;
}	t_has_c;

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;

typedef struct s_cub {
	int		rows;
	int		cols;
	int		start_pos[2];
	char	**map;
}	t_cub;

#endif
