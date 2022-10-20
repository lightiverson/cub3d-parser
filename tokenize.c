#include "tokenize.h"

void	print_map_elements(t_map_element *head)
{
	while (head)
	{
		printf("head->map_element = |%s|\n", head->map_element);
		printf("head->type = %i\n", head->type);
		head = head->next;
	}
}

static void	free_splitted_array(char **splitted_array)
{
	int	i;

	i = 0;
	while (splitted_array[i])
	{
		free(splitted_array[i]);
		i++;
	}
	free(splitted_array);
}

void	free_map_elements(t_map_element *head)
{
	t_map_element	*tmp;

	while (head != 0)
	{
		tmp = head;
		head = head->next;
		free(tmp->map_element);
		free(tmp);
	}
}

static t_map_element	*init_map_element(char *map_element, int type)
{
	t_map_element *node;

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

void	tokenize_map_element(char *input_elem, int type, t_map_element **lst)
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

t_map_element	*tokenizer(char *file_str)
{
	char			**split_a;
	unsigned int	i;
	t_map_element	*map_elements;

	split_a = ft_split(file_str, '\n');
	if (!split_a)
	{
		perror("Error: malloc()\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	map_elements = 0;
	while (split_a[i])
	{
		if (!strncmp(split_a[i], "NO ", 3))
			tokenize_map_element(split_a[i], 0, &map_elements);
		else if (!strncmp(split_a[i], "SO ", 3))
			tokenize_map_element(split_a[i], 0, &map_elements);
		else if (!strncmp(split_a[i], "WE ", 3))
			tokenize_map_element(split_a[i], 0, &map_elements);
		else if (!strncmp(split_a[i], "EA ", 3))
			tokenize_map_element(split_a[i], 0, &map_elements);
		else if (!strncmp(split_a[i], "F ", 2))
			tokenize_map_element(split_a[i], 1, &map_elements);
		else if (!strncmp(split_a[i], "C ", 2))
			tokenize_map_element(split_a[i], 1, &map_elements);
		else
		{
			tokenize_map_element(split_a[i], 2, &map_elements);
			// printf("Wat moeten we hier doen? Map element handelen?\n");
		}
		i++;
	}
	free_splitted_array(split_a);
	return (map_elements);
}
