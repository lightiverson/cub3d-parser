#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validate_map.h"

// void floodfill(char *map[], int row_pos, int col_pos, int *is_valid, int rows, int cols)
// {
//     if (!is_valid)
//         return;
//     if (col_pos == cols || row_pos == rows || col_pos < 0 || row_pos < 0)
//     {
//         *is_valid = 0;
//         return;
//     }
//     if (map[row_pos][col_pos] == '1')
//         return;
//     if (map[row_pos][col_pos] == ' ')
//         return;
//     if (map[row_pos][col_pos] == 'N' || map[row_pos][col_pos] == 'E' || map[row_pos][col_pos] == 'S' || map[row_pos][col_pos] == 'W')
//         map[row_pos][col_pos] = '0';
//     if (map[row_pos][col_pos] == '0')
//         map[row_pos][col_pos] = '1';
//     floodfill(map, row_pos, col_pos + 1, is_valid, rows, cols); // rechts
//     floodfill(map, row_pos + 1, col_pos, is_valid, rows, cols); // onder
//     floodfill(map, row_pos, col_pos - 1, is_valid, rows, cols); // links
//     floodfill(map, row_pos - 1, col_pos, is_valid, rows, cols); // boven
//     return;
// }

// typedef struct _stack 
// {
//     int current_row;
//     int current_col;
//     struct _stack *next;
// } stack;

// void pop(stack **Q)
// { 
//     (*Q) = (*Q)->next;
// }

// void push(stack **Q, int current_row, int current_col)
// {
//     stack *n;

//     n = malloc(sizeof(*n));
//     n->current_row = current_row;
//     n->current_col = current_col;
//     n->next = *Q;
//     *Q = n;
// }

// void itter_floodfill(char *map[], int current_row, int current_pos, int rows, int cols)
// {
//     stack *Q;
//     stack *n;

//     Q = malloc(sizeof(*Q));
//     n = malloc(sizeof(*n));

//     Q->current_row = current_row;
//     Q->current_col = current_pos;
//     Q->next = 0;

//     while (Q)
//     {
//         n = Q;
//         if (n->current_row < 0 || n->current_col < 0 || n->current_row == rows || n->current_col == cols)
//         {
//             printf("Invalid\n");
//             return;
//         }
//         if (map[current_row][current_pos] == 'N' || map[current_row][current_pos] == 'E' || map[current_row][current_pos] == 'S' || map[current_row][current_pos] == 'W')
//             map[current_row][current_pos] = '0';
//         pop(&Q);
//         if (map[n->current_row][n->current_col] == '0')
//         {
//             map[n->current_row][n->current_col] = '1';
//             push(&Q, n->current_row, n->current_col + 1);
//             push(&Q, n->current_row - 1, n->current_col);
//             push(&Q, n->current_row, n->current_col - 1);
//             push(&Q, n->current_row + 1, n->current_col);
//         }
//     }
//     printf("Valid\n");
// }

int main() {
    int     cols;
    int     rows;
    char    **map;

    map = calloc(4, sizeof(*map));
    if (!map)
        exit(EXIT_FAILURE);
    map[0] = strdup("1111");
    map[1] = strdup("1N01");
    map[2] = strdup("1011");
    cols = 4;
    rows = 3;

    itter_floodfill(map, 1, 1, rows, cols);

    return (0);
}

// int main() {
//     int     is_valid;
//     int     cols;
//     int     rows;
//     char    **map;

//     map = calloc(4, sizeof(*map));
//     if (!map)
//         exit(EXIT_FAILURE);
//     map[0] = strdup("1011");
//     map[1] = strdup("1N1");
//     map[2] = strdup("1111");
//     cols = 4;
//     rows = 3;
//     is_valid = 1; // true

//     floodfill(map, 1, 1, &is_valid, rows, cols);

//     if (!is_valid)
//         printf("Map is invalid\n");
//     else
//         printf("Map is valid!\n");

//     return 0;
// }