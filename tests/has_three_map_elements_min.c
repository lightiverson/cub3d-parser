#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../tokenize.h"
#include "../validate_map.h"

static char			*file_str;
static t_map_element	*map_element;

static void teardown(void) {
	free(file_str);
	free_map_elements(map_element);
}

Test(has_three_map_elements_min, te_veel, .fini = teardown)
{
	int				map_fd;

	map_fd = get_map_fd("./maps/has_three_elements_min_0.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);

	cr_assert(has_three_map_elements_min(map_element));
}

Test(has_three_map_elements_min, gelijk, .fini = teardown)
{
	int				map_fd;

	map_fd = get_map_fd("./maps/has_three_elements_min_1.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);

	cr_assert(has_three_map_elements_min(map_element));
}

Test(has_three_map_elements_min, te_weinig, .fini = teardown)
{
	int				map_fd;

	map_fd = get_map_fd("./maps/has_three_elements_min_2.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);

	cr_assert(not(has_three_map_elements_min(map_element)));
}

Test(has_three_map_elements_min, geen, .fini = teardown)
{
	int				map_fd;

	map_fd = get_map_fd("./maps/has_three_elements_min_3.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);

	cr_assert(not(has_three_map_elements_min(map_element)));
}
