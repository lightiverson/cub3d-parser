#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"

static char			*file_str;
static t_map_element	*map_element;

static void teardown(void) {
	free(file_str);
	free_map_elements(map_element);
}

Test(single_start_position, no_start_position, .fini = teardown)
{
	int				map_fd;
	bool			b;

	map_fd = get_map_fd("./maps/no_start_position.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_single_start_position(map_element);

	cr_assert(not(b));
}

Test(single_start_position, one_start_position, .fini = teardown)
{
	int				map_fd;
	bool			b;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_single_start_position(map_element);

	cr_assert(b);
}

Test(single_start_position, multiple_start_positions, .fini = teardown)
{
	int				map_fd;
	bool			b;

	map_fd = get_map_fd("./maps/multiple_start_positions.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	b = has_single_start_position(map_element);

	cr_assert(not(b));
}
