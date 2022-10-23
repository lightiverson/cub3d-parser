#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../tokenize.h"
#include "../file_to_str.h"

Test(is_sorted, simple)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	bool			sorted;

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	sorted = is_sorted(map_element);

	cr_assert(sorted);
}
