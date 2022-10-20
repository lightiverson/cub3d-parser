#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../tokenize.h"
#include "../file_to_str.h"

Test(input_files, valid)
{
	unsigned int	i;
	int				map_fd;
	char			*file_str;
	t_map_element	*lst;
	char			*expected[] = {
		"NO ./path_to_the_north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		"F 220,100,0",
		"C 225,30,0",
		0
	};

	i = 0;
	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	lst = tokenizer(file_str);
	while (lst)
	{
		cr_assert(eq(str, lst->map_element, expected[i]));
		lst = lst->next;
		i++;
	}
}