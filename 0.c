#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void floodfill(char *map[], int row_pos, int col_pos, int *is_valid, int rows, int cols)
{
    if (!is_valid)
        return;
    if (col_pos == cols || row_pos == rows || col_pos < 0 || row_pos < 0)
    {
        *is_valid = 0;
        return;
    }
    if (map[row_pos][col_pos] == '1')
        return;
    if (map[row_pos][col_pos] == ' ')
        return;
    if (map[row_pos][col_pos] == 'N' || map[row_pos][col_pos] == 'E' || map[row_pos][col_pos] == 'S' || map[row_pos][col_pos] == 'W')
        map[row_pos][col_pos] = '0';
    if (map[row_pos][col_pos] == '0')
        map[row_pos][col_pos] = '1';
    floodfill(map, row_pos, col_pos + 1, is_valid, rows, cols); // rechts
    floodfill(map, row_pos + 1, col_pos, is_valid, rows, cols); // onder
    floodfill(map, row_pos, col_pos - 1, is_valid, rows, cols); // links
    floodfill(map, row_pos - 1, col_pos, is_valid, rows, cols); // boven
    return;
}

int main() {
    int     is_valid;
    int     cols;
    int     rows;
    char    **map;

    cols = 4;
    rows = 3;
    map = calloc(4, sizeof(*map));
    if (!map)
        exit(EXIT_FAILURE);
    map[0] = strdup("1011");
    map[1] = strdup("1N1");
    map[2] = strdup("1111");
    is_valid = 1; // true

    floodfill(map, 1, 1, &is_valid, rows, cols);

    if (!is_valid)
        printf("Map is invalid\n");
    else
        printf("Map is valid!\n");

    return 0;
}