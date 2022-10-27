/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:59:44 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/10/27 11:58:51 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static t_map_element	*init_map_element(char *map_element, int type)
{
	t_map_element	*node;

	node = malloc(sizeof(*node));
	if (!node)
	{
		perror("Error: malloc()\n");
		exit(1);
	}
	node->map_element = map_element;
	node->type = type;
	node->next = 0;
	return (node);
}

static void	map_elements_add_back(t_map_element **lst, t_map_element *new)
{
	t_map_element	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void	tokenize_map_element(char *input_elem, int type,
	t_map_element **lst)
{
	char			*s;
	t_map_element	*node;

	s = strdup(input_elem);
	if (!s)
	{
		perror("Error: malloc()\n");
		exit(1);
	}
	node = init_map_element(s, type);
	map_elements_add_back(lst, node);
}

static void	inner_tokenizer(char *split_a_i, t_map_element **map_elements)
{
	if (ft_strnstr(split_a_i, "NO ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_CARDINAL, map_elements);
	else if (ft_strnstr(split_a_i, "SO ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_CARDINAL, map_elements);
	else if (ft_strnstr(split_a_i, "WE ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_CARDINAL, map_elements);
	else if (ft_strnstr(split_a_i, "EA ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_CARDINAL, map_elements);
	else if (ft_strnstr(split_a_i, "F ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_FLOOR_CEILING, map_elements);
	else if (ft_strnstr(split_a_i, "C ", ft_strlen(split_a_i)))
		tokenize_map_element(split_a_i, E_FLOOR_CEILING, map_elements);
	else
		tokenize_map_element(split_a_i, E_MAP, map_elements);
}

/*
Except for the map content, each type of element can be separated by one or
more empty line(s).
*/
t_map_element	*tokenizer(char *file_str)
{
	char			**split_a;
	unsigned int	i;
	t_map_element	*map_elements;

	split_a = ft_split(file_str, '\n');
	if (!split_a)
	{
		perror("Error: ft_split()\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	map_elements = 0;
	while (split_a[i])
	{
		inner_tokenizer(split_a[i], &map_elements);
		i++;
	}
	free_splitted_array(split_a);
	return (map_elements);
}
