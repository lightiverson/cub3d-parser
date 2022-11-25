/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:02:22 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/25 15:02:24 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_cub(t_cub *cub)
{
	printf("cub\n");
	printf("{\n");
	printf("\trows = \t\t%i\n", cub->rows);
	printf("\tcols = \t\t%i\n", cub->cols);
	printf("\tstart_pos = \t[%i, %i]\n", cub->start_pos[0], cub->start_pos[1]);
	printf("\tmap = \t\t%p\n", cub->map);
	printf("\tfloor = \t{\n");
	print_rgb(&(cub->floor));
	printf("\tceiling = \t{\n");
	print_rgb(&(cub->ceiling));
}

void	print_exit(char *msg)
{
	printf("%s", msg);
	exit(EXIT_FAILURE);
}

void	print_map_elements(t_map_element *head)
{
	while (head)
	{
		printf("head->map_element = |%s|\n", head->map_element);
		printf("head->type = %i\n", head->type);
		head = head->next;
	}
}

void	print_splitted_a(char **split_a)
{
	int	i;

	i = 0;
	while (split_a[i])
	{
		printf("split_a[%i] \t= |%s|\n", i, split_a[i]);
		i++;
	}
}

void	print_rgb(t_rgb *rgb)
{
	// printf("rgb\n{\n\tr\t=\t%i\n\tg\t=\t%i\n\tb\t=\t%i\n}\n", rgb->r, rgb->g, rgb->b);
	printf("\t\t\t\tr = \t%i\n", rgb->r);
	printf("\t\t\t\tg = \t%i\n", rgb->g);
	printf("\t\t\t\tb = \t%i\n", rgb->b);
	printf("\t\t\t}\n");
}

void	init_has_c(t_has_c *data)
{
	data->has_no = false;
	data->has_so = false;
	data->has_we = false;
	data->has_ea = false;
}

int	count_ptrs(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i])
		i++;
	return (i);
}
