#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../tokenize.h"
#include "../file_to_str.h"

Test(tokenizer, kawish_cub)
{
	unsigned int	i;
	int				map_fd;
	char			*file_str;
	t_map_element	*lst;
	char			*expected[] = {
		"NO ./path_to_the_north_texture",
		"SO ./path_to_the_south_texture",
		"WE ./path_to_the_west_texture",
		"EA ./path_to_the_east_texture",
		"F 220,100,0",
		"C 225,30,0",
		0
	};

	i = 0;
	map_fd = get_map_fd("./maps/kawish.cub");
	file_to_str(map_fd, &file_str);
	lst = tokenizer(file_str);
	while (lst)
	{
		cr_assert(eq(str, lst->map_element, expected[i]));
		lst = lst->next;
		i++;
	}
}

Test(tokenizer, trip_cub)
{
	unsigned int	i;
	int				map_fd;
	char			*file_str;
	t_map_element	*lst;
	char			*expected[] = {
		"      NO ./textures/trip5.xpm",
		"      EA ./textures/trip2.xpm",
		"      SO ./textures/trip3.xpm",
		"  WE ./textures/trip4.xpm",
		"      S ./sprites/tiger.png",
		"     F    38, 38, 38",
		"     C    209, 209, 209",
		0
	};

	i = 0;
	map_fd = get_map_fd("./maps/trip.cub");
	file_to_str(map_fd, &file_str);
	lst = tokenizer(file_str);
	while (lst)
	{
		cr_assert(eq(str, lst->map_element, expected[i]));
		lst = lst->next;
		i++;
	}
}
