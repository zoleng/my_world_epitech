/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "../dotash.h"

void draw_line(sfVector2f pos1, sfVector2f pos2, global global, color color)
{
    int abs_x = abs(pos1.x - pos2.x);
    int abs_y = abs(pos1.y - pos2.y);
    int pixel = 0;

    if (abs_x >= abs_y)
        pixel = abs_x;
    else
        pixel = abs_y;
    abs_x = abs_x / pixel;
    abs_y = abs_y / pixel;
    for (; pixel != 0; pixel--)
    {
        put_pixel(global, pos1, color);
        pos1.x = pos1.x + abs_x;
        pos1.y = pos1.y + abs_y;
    }
}
