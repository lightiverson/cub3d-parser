#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../file_to_str.h"
#include "../validate_map.h"
#include "../ll_to_a_map.h"

Test(to_two_d_array, correct)
{
	int				map_fd;
	char			*file_str;
	t_map_element	*map_element;
	char			**two_d_a;
	int				map_col_size;
	int				map_size;
	unsigned int	i;
	unsigned int	j;

	map_fd = get_map_fd("./maps/kleine.cub");
	file_to_str(map_fd, &file_str);
	map_element = tokenizer(file_str);
	two_d_a = ll_to_a_map(map_element, file_str);

	map_col_size = get_map_col_size(map_element);
	cr_assert(eq(int, 4, map_col_size));

	map_size = get_map_size(map_element);
	cr_assert(eq(int, 3, map_size));

	i = 0;
	j = 0;
	char	*a[] = {
		"1110",
		"1N11",
		"1110",
		0
	};
	while (i < map_size)
	{
		while (j < map_col_size)
		{
			// cr_assert(eq(chr, (*two_d_a)[j], (*a)[j]));
			printf("[%c] vs [%c]\n", two_d_a[i][j], a[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
