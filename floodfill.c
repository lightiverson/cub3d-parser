/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:10:59 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 16:52:13 by kgajadie      ########   odam.nl         */
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
Herschrijf om return en single pointer te gebruiken
*/
void	pop(t_stack **stack)
{
	*stack = (*stack)->next;
}

/*
Herschrijf om return en single pointer te gebruiken
*/
void	push(t_stack **stack, int cr, int cc)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
	{
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	node->cr = cr;
	node->cc = cc;
	node->next = *stack;
	*stack = node;
}

/*
The map must be closed/surrounded by walls, if not the program must return
an error.
*/
bool	itter_floodfill(char *map[], unsigned int pos[2], int rows, int cols)
{
	t_stack	*stack;
	t_stack	*node;

	stack = 0;
	push(&stack, pos[0], pos[1]);
	map[pos[0]][pos[1]] = '0';
	while (stack)
	{
		node = stack;
		if (node->cr < 0 || node->cc < 0 || node->cr == rows
			|| node->cc == cols || map[node->cr][node->cc] == ' '
			|| map[node->cr][node->cc] == 'X')
			return (false);
		pop(&stack);
		if (map[node->cr][node->cc] == '0')
		{
			map[node->cr][node->cc] = '1';
			push(&stack, node->cr - 1, node->cc);
			push(&stack, node->cr, node->cc + 1);
			push(&stack, node->cr + 1, node->cc);
			push(&stack, node->cr, node->cc - 1);
		}
		free(node);
	}
	return (true);
}
