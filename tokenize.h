#ifndef TOKENIZE_H
# define TOKENIZE_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct s_map_element {
	char					*map_element;
	int						type;
	struct s_map_element	*next;
}	t_map_element;

void	free_map_elements(t_map_element *head);
void	tokenize_map_element(char *input_elem, int type, t_map_element **lst);
void	print_map_elements(t_map_element *head);

#endif /* tokenize.h */
