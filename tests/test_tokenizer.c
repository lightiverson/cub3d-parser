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
		"        1111111111111111111111111",
		"        1000000000110000000000001",
		"        1011000001110000000000001",
		"        1001000000000000000000001",
		"111111111011000001110000000000001",
		"100000000011000001110111111111111",
		"11110111111111011100000010001",
		"11110111111111011101010010001",
		"11000000110101011100000010001",
		"10000000000000001100000010001",
		"10000000000000001101010010001",
		"11000001110101011111011110N0111",
		"11110111 1110101 101111010001",
		"11111111 1111111 111111111111",
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
		"     F    38, 38, 38",
		"     C    209, 209, 209",
		"        1111111111111111111111111",
		"        10000000001100000000000011",
		"        100110000011100000000000011",
		"        10010000000000000000000011",
		"111111111011000001110000000000001",
		"100000000011000001110111110111111",
		"11110111111111011100000010001",
		"11110111111111011101010010001",
		"11000000110101011100000000001",
		"10000000000000001100000010001",
		"100011W0000000001101010010001",
		"1100000111010101111101111000111",
		"11111111 1110101 101111010001",
		"11111111 1111111 111111111111",
		"",
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
