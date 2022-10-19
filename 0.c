#include "file_to_str.h"
#include "libft/libft.h"

typedef struct s_map_element {
	char					*map_element;
	int						type;
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
		printf("head->map_element = |%s|\n", head->map_element);
		printf("head->type = %i\n", head->type);
		head = head->next;
	}
}

t_map_element	*init_node(char *map_element, int type)
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

void tokenize_input_elem(char *input_elem, int type, t_map_element **lst)
{
	char			*s;
	t_map_element	*node;

	s = strdup(input_elem);
	if (!s)
	{
		perror("Error: malloc()\n");
		exit(1);
	}
	node = init_node(s, type);
	map_elements_add_back(lst, node);
}

void free_splitted_array(char **splitted_array)
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

void free_map_elements(t_map_element *head)
{
	t_map_element	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->map_element);
		free(tmp);
	}
}

int main (int argc, char *argv[argc + 1])
{
	int				map_fd;
	char			*file_str;
	t_map_element	*lst;
	char			**a;
	unsigned int	i;

	map_fd = get_map_fd(argv[argc - 1]);
	file_to_str(map_fd, &file_str);

	printf("file_to_str = |%s|\n", file_str);

	i = 0;
	lst = 0;
	a = ft_split(file_str, '\n');
	if (!a)
	{
		perror("Error: malloc()\n");
		exit(1);
	}
	while (a[i])
	{
		if (!strncmp(a[i], "NO ", 3))
			tokenize_input_elem(a[i], 0, &lst);
		else if (!strncmp(a[i], "SO ", 3))
			tokenize_input_elem(a[i], 0, &lst);
		else if (!strncmp(a[i], "WE ", 3))
			tokenize_input_elem(a[i], 0, &lst);
		else if (!strncmp(a[i], "EA ", 3))
			tokenize_input_elem(a[i], 0, &lst);
		else if (!strncmp(a[i], "F ", 2))
			tokenize_input_elem(a[i], 1, &lst);
		else if (!strncmp(a[i], "C ", 2))
			tokenize_input_elem(a[i], 1, &lst);
		// else
		// 	printf("Wat moeten we hier doen? Map element handelen?\n");
		i++;
	}
	free(file_str);
	free_splitted_array(a);
	print_map_elements(lst);
	return (0);
}
