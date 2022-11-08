/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:10:59 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/08 16:12:37 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_map.h"

static bool	is_start_pos(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

/*
* Int returnen is op zich niet nodig
* Kan ook gewoon position returnen omdat
* checks al eerder gebeuren
*/
int	get_start_pos(char **two_d_a, unsigned int start_pos[2])
{
	unsigned int	sr;
	unsigned int	sc;

	sr = 0;
	sc = 0;
	while (two_d_a[sr])
	{
		while (two_d_a[sr][sc])
		{
			if (is_start_pos(two_d_a[sr][sc]))
			{
				start_pos[0] = sr;
				start_pos[1] = sc;
				return (1);
			}
			sc++;
		}
		sc = 0;
		sr++;
	}
	return (0);
}
