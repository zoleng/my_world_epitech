/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** map_creator
*/

int **map_creator(int size)
{
    int **map3d = malloc(sizeof(int *) * size);
    int y = 0;

    for (y = 0; y < size; y++)
        map3d[y] = malloc(sizeof(int) * size);
    map3d = my_memset_map(map3d, 0, size, size);
    return (map3d);
}