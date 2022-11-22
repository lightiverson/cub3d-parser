/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_ft_strtol.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:07:42 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/22 18:03:39 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtol.h"

t_data	*init_data(const char *nptr)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		exit(1);
	data->s = nptr;
	data->neg = 0;
	data->cutoff = LONG_MAX;
	data->acc = 0;
	data->any = 0;
	return (data);
}
