/*
** EPITECH PROJECT, 2019
** MUL_bootstrap_my_world
** File description:
** project_iso_point
*/

#define M_PI 3.14159265358979323846
#include <SFML/System/Vector2.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Vertex.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "dotash.h"

sfVector2f project_iso_point(int x, int y, int z, mapper mapper)
{
    int angle_x = (M_PI / 180);
    int angle_y = mapper.rotate_map * (M_PI / 180);
    float twod_point_x;
    float twod_point_y;
    sfVector2f point2d;

    twod_point_x = cos(angle_x) * x - cos(angle_x) * y;
    twod_point_y = sin(angle_y) * y + sin(angle_y) * x - z;
    twod_point_x += mapper.move_map_x;
    twod_point_y += mapper.move_map_y;
    point2d.x = twod_point_x;
    point2d.y = twod_point_y;
    return (point2d);
}

sfVector2f **create_2d_map(int map[][10], mapper mapper)
{
    int z = 0;
    sfVector2f **map2d = malloc(sizeof(sfVector2f *) * 10);

    for (int i = 0; i != 10; i++)
        map2d[i] = malloc(sizeof(sfVector2f) * 10);
    for (int j = 0; j != 10; j++) {
        for (int i = 0; i != 10; i++) {
            map2d[j][i] = project_iso_point(i * 40, j * 40 , map[j][i] * 5, mapper);
        }
    }
    return (map2d);
}

sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2, int z)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    if (z == 1) {
        sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(180, 0, 0)};
        sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(180, 0, 0)};
        sfVertexArray_append(vertex_array, v1);
        sfVertexArray_append(vertex_array, v2);
    } else if (z == 2) {
        sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(0, 0, 100)};
        sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(0, 0, 100)};
        sfVertexArray_append(vertex_array, v1);
        sfVertexArray_append(vertex_array, v2);
    } else {
        sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(0, 180, 0)};
        sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(0, 180, 0)};
        sfVertexArray_append(vertex_array, v1);
        sfVertexArray_append(vertex_array, v2);
    }
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_2d_map(sfRenderWindow *window, sfVector2f **two_d_map, int map[][10])
{
    int volume = 0;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            if (y == 10 - 1 && x == 10 - 1)
                return (0);
            else if (y == 10 - 1) {
                volume = test_volume(map, y, x);
                vertex_x(window, two_d_map, x, y, volume);
            }
            else if (x == 10 - 1) {
                volume = test_volume(map, y, x);
                vertex_y(window, two_d_map, x, y, volume);
            }
            else {
                volume = test_volume(map, y, x);
                vertex_y(window, two_d_map, x, y, volume);
                vertex_x(window, two_d_map, x, y, volume);
            }
        }
    }
    return (0);
}
