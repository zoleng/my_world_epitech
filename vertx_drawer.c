/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** vertx_drawer
*/

#include "dotash.h"

void vertex_x(sfRenderWindow *window, sfVector2f **map_2d, int x, int y, int z)
{
    sfVertexArray *v;

    v = create_line(&(map_2d[y][x]), &(map_2d[y][x + 1]), z);
    sfRenderWindow_drawVertexArray(window, v, NULL);
    sfVertexArray_destroy(v);
}

void vertex_y(sfRenderWindow *window, sfVector2f **map_2d, int x, int y, int z)
{
    sfVertexArray *v;

    v = create_line(&(map_2d[y][x]), &(map_2d[y + 1][x]), z);
    sfRenderWindow_drawVertexArray(window, v, NULL);
    sfVertexArray_destroy(v);
}

