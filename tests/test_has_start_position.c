#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"

Test(start_position, no_start_position)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	bool			b;

	map_fd = get_map_fd("./maps/no_start_position.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_start_position(map_element);

	cr_assert(not(b));
}

Test(start_position, start_position)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	bool			b;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_start_position(map_element);

	cr_assert(b);
}
