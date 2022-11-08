#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"

Test(count_cols, kawish)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	int				number_of_columns;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	number_of_columns = count_columns(map_element);
	cr_assert(eq(int, number_of_columns, 33));
}

Test(count_cols, huisjes)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	int				number_of_columns;

	map_fd = get_map_fd("./maps/huisjes.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	number_of_columns = count_columns(map_element);
	cr_assert(eq(int, number_of_columns, 167));
}
