#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"

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

void	free_splitted_array(char **splitted_array)
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
			tokenize_map_element(a[i], 0, &lst);
		else if (!strncmp(a[i], "SO ", 3))
			tokenize_map_element(a[i], 0, &lst);
		else if (!strncmp(a[i], "WE ", 3))
			tokenize_map_element(a[i], 0, &lst);
		else if (!strncmp(a[i], "EA ", 3))
			tokenize_map_element(a[i], 0, &lst);
		else if (!strncmp(a[i], "F ", 2))
			tokenize_map_element(a[i], 1, &lst);
		else if (!strncmp(a[i], "C ", 2))
			tokenize_map_element(a[i], 1, &lst);
		// else
		// 	printf("Wat moeten we hier doen? Map element handelen?\n");
		i++;
	}
	print_map_elements(lst);
	free(file_str);
	free_splitted_array(a);
	free_map_elements(lst);
	return (0);
}
