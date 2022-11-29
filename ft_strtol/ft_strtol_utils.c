/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_ft_strtol.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:07:42 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/24 10:48:21 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtol.h"

void	init_data(t_data *data, const char *nptr)
{
	data->s = nptr;
	data->neg = 0;
	data->cutoff = LONG_MAX;
	data->acc = 0;
	data->any = 0;
}
