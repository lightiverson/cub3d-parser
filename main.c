#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"

int main (int argc, char *argv[argc + 1])
{
	int				map_fd;
	char			*file_str;
	t_map_element	*lst;

	if (argc != 2)
	{
		printf("Error: Invalid amount of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (!is_dot_cub_file(argv[argc - 1]))
	{
		printf("Error: Invalid file extension\n");
		exit(EXIT_FAILURE);
	}
	
	map_fd = get_map_fd(argv[argc - 1]);
	file_to_str(map_fd, &file_str);
	printf("file_to_str = |%s|\n", file_str);

	lst = tokenizer(file_str);
	print_map_elements(lst);

	free(file_str);
	free_map_elements(lst);

	return (EXIT_SUCCESS);
}
