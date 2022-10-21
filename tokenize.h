#ifndef TOKENIZE_H
# define TOKENIZE_H

/* Public libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Private libraries */
#include "libft/libft.h"

typedef struct s_map_element {
	char					*map_element;
	int						type;
	struct s_map_element	*next;
}	t_map_element;

enum e_element_types {
	C_DIRECTION = 1,
	FLOOR_CEILING,
	MAP
};

/* tokenize.c */

bool			is_dot_cub_file(char *arg);
void			free_map_elements(t_map_element *head);
void			tokenize_map_element(char *input_elem, int type, t_map_element **lst);
void			print_map_elements(t_map_element *head);
t_map_element	*tokenizer(char *file_str);
bool			is_sorted(t_map_element *map_element);

#endif /* tokenize.h */
