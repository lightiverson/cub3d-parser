/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor_ceiling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:57:43 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/29 14:45:28 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*
De info kan alleen seperated worden door 1 of meer spaces
dus er moeten getalen en kommas in zitten
   F   2 2 2 , 1 0  0  ,   0    is een valid floor color
*/
int	strip_spaces(char *s)
{
	char	*p2;

	if (!s)
		return (1);
	while (*s)
	{
		if (isspace(*s))
		{
			p2 = s;
			while (isspace(*p2))
				p2++;
			ft_memcpy(s, p2, strlen(s));
		}
		s++;
	}
	return (0);
}

int	convert_to_int(char *str)
{
	char	*endptr;
	long	val;

	errno = 0; /* To distinguish success/failure after call */
	val = ft_strtol(str, &endptr);
	if (errno != 0) /* Check for various possible errors */
	{
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (endptr == str)
		print_exit("Error: no digits were found\n");
	if (*endptr != '\0') /* If we got here, strtol() successfully parsed a number */ /* Not necessarily an error... */
	{
		printf("Error: found characters after number: \"%s\"\n", endptr);
		exit(EXIT_FAILURE);
	}
	if (val < INT_MIN || val > INT_MAX)
		print_exit("Error: int overflow/underflow\n");
	if (val < 0 || val > 255)
		print_exit("Error: int not between 8 bits\n");
	return ((int) val);
}

t_rgb	build_rgb(char *str)
{
	char	**splitted_array;
	t_rgb	rgb;

	if (*str != 'F' && *str != 'C')
		print_exit("Error: invalid floor ceiling string\n");
	str++;
	splitted_array = ft_split(str, ',');
	if (!splitted_array)
		print_exit("Error: malloc failed");
	if (count_ptrs(splitted_array) != 3)
		print_exit("Error: invalid floor ceiling string\n");
	rgb.r = convert_to_int(splitted_array[0]);
	rgb.g = convert_to_int(splitted_array[1]);
	rgb.b = convert_to_int(splitted_array[2]);
	free_splitted_array(splitted_array);
	return (rgb);
}

t_rgb	parse_floor_ceiling(t_map_element *map_element, int sub_type)
{
	while (map_element)
	{
		if (map_element->sub_type == sub_type)
			break ;
		map_element = map_element->next;
	}
	if (!map_element)
		print_exit("Error: parser()");
	strip_spaces(map_element->map_element);
	return (build_rgb(map_element->map_element));
}

char	**parse_cordinal(t_map_element *map_element, int sub_type)
{
	char	**splitted_array;
	while (map_element)
	{
		if (map_element->sub_type == sub_type)
			break ;
		map_element = map_element->next;
	}
	if (!map_element)
		print_exit("Error: parser()");
	splitted_array = ft_split(map_element->map_element, ' ');
	if (!splitted_array)
		print_exit("Error: malloc()\n");
	return (splitted_array);
}
