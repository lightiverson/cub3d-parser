#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"

Test(multiple_start_positions, multiple_start_positions)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	bool			b;

	map_fd = get_map_fd("./maps/multiple_start_positions.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_multiple_start_positions(map_element);

	cr_assert(b);
}

Test(multiple_start_positions, single_start_position)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	bool			b;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_multiple_start_positions(map_element);

	cr_assert(not(b));
}