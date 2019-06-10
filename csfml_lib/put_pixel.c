/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "../dotash.h"

void put_pixel(global *global, sfVector2i pos, color *color)
{
    int i = 4 * (pos.y * global->framebuffer->width + pos.x);

    global->framebuffer->pixels[i] = color->R;
    global->framebuffer->pixels[i + 1] = color->G;
    global->framebuffer->pixels[i + 2] = color->B;
    global->framebuffer->pixels[i + 3] = 255;
}
