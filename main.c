#include "file_to_str.h"
#include "libft/libft.h"
#include "tokenize.h"

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

	lst = tokenizer(file_str);
	print_map_elements(lst);

	free(file_str);
	free_map_elements(lst);

	return (0);
}
