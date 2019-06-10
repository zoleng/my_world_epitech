/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "../dotash.h"

void set_color(int R, int G, int B, color *color)
{
    printf("R:%d\n", R);
    color->R = R;
    color->G = G;
    color->B = B;
    printf("color->R:%d\n", color->R);
}
