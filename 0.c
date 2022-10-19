#include "file_to_str.h"

typedef struct s_map_element {
	char					*map_element;
	size_t					len;
	struct s_map_element	*next;
}	t_map_element;

int	get_map_fd(const char *map_name)
{
	int	map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
	{
		perror("Error: open()\n");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

void print_map_elements(t_map_element *head)
{
	while (head)
	{
		printf("head->map_element = %.*s\n", (int)head->len, head->map_element);
		// printf("head->len = %lu\n", head->len);
		head = head->next;
	}
}

t_map_element	*init_node(char *map_element, size_t len)
{
	t_map_element *node;

	node = malloc(sizeof(*node));
	if (!node)
		exit(1);
	node->map_element = map_element;
	node->len = len;
	node->next = 0;
	return (node);
}

void	map_elements_add_back(t_map_element **lst, t_map_element *new)
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

void tokenize_input_elem(char **file_str_dup, t_map_element	**lst)
{
	size_t len;
	char			*needle;
	t_map_element	*leeg;

	len = 0;
	needle = *file_str_dup;
	while (**file_str_dup != '\n')
	{
		len++;
		(*file_str_dup)++;
	}
	leeg = init_node(needle, len);
	map_elements_add_back(lst, leeg);
}

int main (int argc, char *argv[argc + 1])
{
	int				map_fd;
	char			*file_str;
	char			*file_str_dup;
	t_map_element	*lst;
	t_map_element	*leeg;
	char			*needle;

	map_fd = get_map_fd("map.cub");
	file_to_str(map_fd, &file_str);

	printf("file_to_str = |%s|\n", file_str);

	lst = 0;
	unsigned int len = 0;
	file_str_dup = file_str;
	while (*file_str_dup)
	{
		if (!strncmp(file_str_dup, "NO ", 3))
		{
			tokenize_input_elem(&file_str_dup, &lst);
			// needle = file_str_dup;
			// while (*file_str_dup != '\n')
			// {
			// 	len++;
			// 	file_str_dup++;
			// }
			// leeg = init_node(needle, len);
			// map_elements_add_back(&lst, leeg);
			// len = 0;
		}
	
		else if (!strncmp(file_str_dup, "SO ", 3))
		{
			tokenize_input_elem(&file_str_dup, &lst);
			// needle = file_str_dup;
			// while (*file_str_dup != '\n')
			// {
			// 	len++;
			// 	file_str_dup++;
			// }
			// leeg = init_node(needle, len);
			// map_elements_add_back(&lst, leeg);
			// len = 0;
		}
	
		else if (!strncmp(file_str_dup, "WE ", 3))
		{
			tokenize_input_elem(&file_str_dup, &lst);
			// needle = file_str_dup;
			// while (*file_str_dup != '\n')
			// {
			// 	len++;
			// 	file_str_dup++;
			// }
			// leeg = init_node(needle, len);
			// map_elements_add_back(&lst, leeg);
			// len = 0;
		}
	
		else if (!strncmp(file_str_dup, "F ", 2))
		{
			tokenize_input_elem(&file_str_dup, &lst);
			// needle = file_str_dup;
			// while (*file_str_dup != '\n')
			// {
			// 	len++;
			// 	file_str_dup++;
			// }
			// leeg = init_node(needle, len);
			// map_elements_add_back(&lst, leeg);
			// len = 0;
		}
	
		else if (!strncmp(file_str_dup, "C ", 2))
		{
			tokenize_input_elem(&file_str_dup, &lst);
			// needle = file_str_dup;
			// while (*file_str_dup != '\n')
			// {
			// 	len++;
			// 	file_str_dup++;
			// }
			// leeg = init_node(needle, len);
			// map_elements_add_back(&lst, leeg);
			// len = 0;
		}
	
		file_str_dup++;
	}
	print_map_elements(lst);
	return (0);
}
