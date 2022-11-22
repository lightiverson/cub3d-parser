#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "libft/libft.h"
#include "tokenize.h"

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
			memmove(s, p2, strlen(s));
		}
		s++;
	}
	return (0);
}

typedef struct s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;

void print_rgb(t_rgb *rgb)
{
	printf("rgb\n{\n\tr\t=\t%i\n\tg\t=\t%i\n\tb\t=\t%i\n}\n", rgb->r, rgb->g, rgb->b);
}

int beta(char *str)
{
	char	*endptr
	char	*str;
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
		printf("Error: int not between 8 bits")
		exit(EXIT_FAILURE);
	}
	return ((int) val);
}

void alpha(char *str)
{
	char    **splitted_array;
	t_rgb   *rgb;

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
	// if (count_ptrs(splitted_array) != 3)
	// {
	//     printf("Error: invalid floor ceiling string");
	//     exit(EXIT_FAILURE);
	// }

	// call functie die strtol/atoi called -> en of exit -> of een valid int returned (kan ook range check in)

	// converteer elke element in splitted_array naar een int
	// check of de int tussen de 0 en 255 zit
	rgb = malloc(sizeof(*rgb));
	rgb->r = ft_atoi(splitted_array[0]);
	// als overflow is -> exit
	// als underflow is -> exit
	// als letters ergens in de string voorkomen -> exit
	// als de geconverteerde int kleiner dan 0 of groter dan 255 is -> exit
	print_rgb(rgb);

	// rgb->r = splitted_array[0];
	// rgb->g = splitted_array[1];
	// rgb->b = splitted_array[2];
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