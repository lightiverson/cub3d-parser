#include "tokenize.h"

bool is_sorted_twee(t_map_element *map_element)
{
	int	p;
	// kan map_element 0 zijn?
	if (!map_element)
		return (false);
	p = map_element->type;
	while (map_element)
	{
		if (map_element->type < p)
			return (false);
		p = map_element->type;
		map_element = map_element->next;
	}
	return (true);
}

bool is_sorted(t_map_element *map_element)
{
	bool has_encountered_type_three;

	has_encountered_type_three = false;
	while (map_element)
	{
		if (map_element->type == E_MAP)
			has_encountered_type_three = true;
		if (has_encountered_type_three && map_element->type < E_MAP)
			return (false);
		map_element = map_element->next;
	}
	return (true);
}

bool is_dot_cub_file(char *arg)
{
	size_t	len;
	char	*extension;

	len = strlen(arg);
	if (len < 4)
		return (false);
	extension = arg + len - 4;
	if (strncmp(extension, ".cub\0", 5))
		return (false);
	return (true);
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

void	print_splitted_a(char **split_a)
{
	unsigned int	i;

	i = 0;
	while (split_a[i])
	{
		printf("split_a[%i] = |%s|\n", i, split_a[i]);
		i++;
	}
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
	// print_splitted_a(split_a);
	i = 0;
	map_elements = 0;
	while (split_a[i])
	{
		if (ft_strnstr(split_a[i], "NO ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_CARDINAL, &map_elements);
		else if (ft_strnstr(split_a[i], "SO ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_CARDINAL, &map_elements);
		else if (ft_strnstr(split_a[i], "WE ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_CARDINAL, &map_elements);
		else if (ft_strnstr(split_a[i], "EA ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_CARDINAL, &map_elements);
		else if (ft_strnstr(split_a[i], "F ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_FLOOR_CEILING, &map_elements);
		else if (ft_strnstr(split_a[i], "C ", ft_strlen(split_a[i])))
			tokenize_map_element(split_a[i], E_FLOOR_CEILING, &map_elements);
		else
			tokenize_map_element(split_a[i], E_MAP, &map_elements);
		i++;
	}
	free_splitted_array(split_a);
	return (map_elements);
}
