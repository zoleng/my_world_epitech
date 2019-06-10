/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_line
*/

sfVertexArray *create_line_normal(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(0, 180, 0)};
    sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(0, 180, 0)};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *create_line_down(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(0, 180, 0)};
    sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(0, 180, 0)};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *create_line_up(sfVector2f *p1, sfVector2f *p2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex v1 = {.position = *p1, .color = sfColor_fromRGB(0, 180, 0)};
    sfVertex v2 = {.position = *p2, .color = sfColor_fromRGB(0, 180, 0)};

    sfVertexArray_append(vertex_array, v1);
    sfVertexArray_append(vertex_array, v2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}