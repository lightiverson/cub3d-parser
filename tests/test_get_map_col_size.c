#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"

Test(map_col_size, kawish)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	int				map_col_size;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	map_col_size = get_map_col_size(map_element);
	cr_assert(eq(int, map_col_size, 33));
}

Test(map_col_size, huisjes)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	int				map_col_size;

	map_fd = get_map_fd("./maps/huisjes.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	map_col_size = get_map_col_size(map_element);
	cr_assert(eq(int, map_col_size, 167));
}
