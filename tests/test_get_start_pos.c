#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"
#include "../ll_to_a_map.h"

Test(start_pos, correct)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	char			**two_d_a;
	unsigned int	start_pos[2];

	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	two_d_a = ll_to_a_map(map_element, file_str);

	cr_assert(get_start_pos(two_d_a, start_pos));
}
