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

Test(map_col_size, kawish, .fini = teardown)
{
	int				map_fd;
	int				map_col_size;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	map_col_size = get_map_col_size(map_element);

	cr_assert(eq(int, map_col_size, 33));
}

Test(map_col_size, huisjes, .fini = teardown)
{
	int				map_fd;
	int				map_col_size;

	map_fd = get_map_fd("./maps/huisjes.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	map_col_size = get_map_col_size(map_element);

	cr_assert(eq(int, map_col_size, 167));
}
