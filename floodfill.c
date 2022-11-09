/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:10:59 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/09 18:03:31 by kgajadie      ########   odam.nl         */
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

/*
The map must be closed/surrounded by walls, if not the program must return
an error.
*/
void	floodfill(char *map[], int row_pos, int col_pos, bool *is_valid, int rows, int cols)
{
	if (!is_valid)
		return;
	if (col_pos == cols || row_pos == rows || col_pos < 0 || row_pos < 0)
	{
		*is_valid = false;
		return;
	}
	if (map[row_pos][col_pos] == 'X' || map[row_pos][col_pos] == ' ')
	{
		*is_valid = false;
		return;
	}
	if (map[row_pos][col_pos] == '1')
		return;
	if (map[row_pos][col_pos] == 'N' || map[row_pos][col_pos] == 'E' || map[row_pos][col_pos] == 'S' || map[row_pos][col_pos] == 'W')
		map[row_pos][col_pos] = '0';
	if (map[row_pos][col_pos] == '0')
		map[row_pos][col_pos] = '1';
	floodfill(map, row_pos, col_pos + 1, is_valid, rows, cols);
	floodfill(map, row_pos + 1, col_pos, is_valid, rows, cols);
	floodfill(map, row_pos, col_pos - 1, is_valid, rows, cols);
	floodfill(map, row_pos - 1, col_pos, is_valid, rows, cols);
	return;
}
