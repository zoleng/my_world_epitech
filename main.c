/*
** EPITECH PROJECT, 2019
** h
** File description:
** 
*/


#define MAP_X 10
#define MAP_Y 10

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "dotash.h"

t_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    t_framebuffer *framebuffer = malloc(sizeof(t_framebuffer));
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 4);
    return(framebuffer);
}

struct global *make_global(void)
{
    global *global = malloc(sizeof (global));

    global->texture = sfTexture_create(800, 600);
    global->framebuffer = framebuffer_create(800, 600);
    global->sprite = sfSprite_create();
    sfSprite_setTexture(global->sprite, global->texture, sfTrue);
    return (global);
}

void main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};
    sfEvent click;
    sfMouseButtonEvent mouse;
    int i = 0;
    int j = 0;
    global *global = make_global();
    sfVector2i pos;
    color *color = malloc(sizeof (color));
    sfTime time;
    sfFont* font;
    sfText* text;

    font = sfFont_createFromFile("Technology.ttf");
    if (!font)
        return 84;
    text = sfText_create();
    sfText_setString(text, "  use SPACE to raise, SHIFT and SPACE to low\n  use arrow keys to select case\n Z, Q, S and D to move the map\n R and F to rotate the map");
    sfText_setColor(text, sfGreen);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    
    struct mapper mapper;
    mapper.rotate_map = 450;
    mapper.move_map_x =  380;
    mapper.move_map_y =  110;
    
    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
                                   "Les gentils",
                                   sfDefaultStyle,
                                   NULL);
    pos.x = 0;
    pos.y = 0;
    
    int map[MAP_Y][MAP_X] = {
    {0, 0, 0, 0, 0, 0, 6, 8, 5, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -7, 0, 0, 0, 0},
    {0, 0, 2, -7, -6, -8, 0, 0, 0, 0},
    {0, 0, 0, 0, -9, -8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    draw_2d_map(window, create_2d_map(map, mapper), map);

    while (sfRenderWindow_isOpen(window)) {
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            usleep(1000);
            mapper.move_map_x += 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyD)) {
            usleep(1000);
            mapper.move_map_x -= 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            usleep(1000);
            mapper.move_map_y += 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyS)) {
            usleep(1000);
            mapper.move_map_y -= 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            usleep(500);
            mapper.rotate_map += 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            usleep(500);
            mapper.rotate_map -= 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
                usleep(30000);
                map[j][i] -= 2;
                map[j][i + 1] -= 1;
                map[j][i - 1] -= 1;
                map[j - 1][i] -= 1;
                map[j + 1][i] -= 1;
            }
            else {
                usleep(30000);
                map[j][i] += 2;
                map[j + 1][i] += 1;
                map[j - 1][i] += 1;
                map[j][i + 1] += 1;
                map[j][i - 1] += 1;
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            usleep(100);
            j -= 1;
            if (j < 0)
                j = 10;
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            usleep(100);
            j += 1;
            if (j > 10)
                j = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            usleep(100);
            i += 1;
            if (i > 10)
                i = 0;
        }
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            usleep(100);
            i -= 1;
            if (i < 0)
                i = 10;
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_2d_map(window, create_2d_map(map, mapper), map);
        sfTexture_updateFromPixels(global->texture,
                                   global->framebuffer->pixels,
                                   global->framebuffer->width,
                                   global->framebuffer->height,
                                   0, 0);
        sfRenderWindow_drawSprite(window, global->sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);

        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &click)) {
            if (click.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                free(map);
            }
        }
    }
    sfRenderWindow_destroy(window);
}

