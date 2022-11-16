/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floodfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:10:59 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/16 13:33:17 by kgajadie      ########   odam.nl         */
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

typedef struct s_stack
{
	int	current_row;
	int	current_col;
	struct s_stack *next;
}	t_stack;

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
void	push(t_stack **stack, int current_row, int current_col)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
	{
		perror("Error: malloc()");
		exit(EXIT_FAILURE);
	}
	node->current_row = current_row;
	node->current_col = current_col;
	node->next = *stack;
	*stack = node;
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	itter_floodfill(char *map[], int current_row, int current_col, int rows, int cols)
{
	t_stack	*stack;
	t_stack	*node;

	stack = 0;
	push(&stack, current_row, current_col);
	map[current_row][current_col] = '0';
	while (stack)
	{
		node = stack;
		if (node->current_row < 0 || node->current_col < 0 || node->current_row == rows || node->current_col == cols)
		{
			printf("Invalid\n");
			free_stack(stack);
			return;
		}
		if (map[node->current_row][node->current_col] == ' ' || map[node->current_row][node->current_col] == 'X')
		{
			printf("Invalid\n");
			free_stack(stack);
			return;
		}
		pop(&stack);
		if (map[node->current_row][node->current_col] == '0')
		{
			map[node->current_row][node->current_col] = '1';
			push(&stack, node->current_row - 1, node->current_col);
			push(&stack, node->current_row, node->current_col + 1);
			push(&stack, node->current_row + 1, node->current_col);
			push(&stack, node->current_row, node->current_col - 1);
		}
		free(node);
	}
	printf("Valid\n");
}
