/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor_ceiling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kgajadie <kgajadie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 16:57:43 by kgajadie      #+#    #+#                 */
/*   Updated: 2022/11/22 18:00:56 by kgajadie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_floor_ceiling.h"

void print_rgb(t_rgb *rgb)
{
	printf("rgb\n{\n\tr\t=\t%i\n\tg\t=\t%i\n\tb\t=\t%i\n}\n", rgb->r, rgb->g, rgb->b);
}

// de info kan alleen seperated worden door 1 of meer spaces
// dus er moeten getalen en kommas in zitten
//    F   2 2 2 , 1 0  0  ,   0    is een valid floor color
int strip_spaces(char *s)
{
	char *p2;

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

int beta(char *str)
{
	char	*endptr;
	long	val;

	errno = 0;    /* To distinguish success/failure after call */
	val = ft_strtol(str, &endptr);
	if (errno != 0) /* Check for various possible errors */
	{
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (endptr == str)
	{
		printf("Error: no digits were found\n");
		exit(EXIT_FAILURE);
	}
	if (*endptr != '\0') /* If we got here, strtol() successfully parsed a number */ /* Not necessarily an error... */
	{
		printf("Error: found characters after number: \"%s\"\n", endptr); 
		exit(EXIT_FAILURE);
	}
	if (val < INT_MIN || val > INT_MAX )
	{
		printf("Error: int overflow/underflow\n");
		exit(EXIT_FAILURE);
	}
	if (val < 0 || val > 255)
	{
		printf("Error: int not between 8 bits");
		exit(EXIT_FAILURE);
	}
	return ((int) val);
}

void alpha(char *str)
{
	char	**splitted_array;
	t_rgb	*rgb;

	printf("|%c|\n", *str);
	if (*str != 'F' && *str != 'C')
	{
		printf("Error: invalid floor ceiling string\n");
		exit(EXIT_FAILURE);
	}
	str++;
	splitted_array = ft_split(str, ',');
	if (!splitted_array)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (count_ptrs(splitted_array) != 3)
	{
		printf("Error: invalid floor ceiling string");
		exit(EXIT_FAILURE);
	}
	rgb = malloc(sizeof(*rgb));
	rgb->r = ft_atoi(splitted_array[0]);
	rgb->r = beta(splitted_array[0]);
	rgb->g = beta(splitted_array[1]);
	rgb->b = beta(splitted_array[2]);
	print_rgb(rgb);
}

// int main(void)
// {
// 	char *s = strdup("   F   2 2 0 , 1 0  0  ,   0   ");
// 	// char *s = strdup("F 220,100,0");

// 	strip_spaces(s);
// 	printf("|%s|\n", s);

// 	int i = atoi("F220");
// 	printf("i = %i\n", i);

// 	alpha(s);
// }