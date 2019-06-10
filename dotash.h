/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/
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

typedef struct s_framebuffer
{
    unsigned char *pixels;
    unsigned int width;
    unsigned int height;
} t_framebuffer;

typedef struct window_info window_info;
struct window_info
{
    int height;
    int width;
};

typedef struct color color;
struct color
{
    int R;
    int G;
    int B;
    int A;
};

typedef struct mapper mapper;
struct mapper
{
    int rotate_map;
    int move_map_x;
    int move_map_y;
};

typedef struct global global;
struct global
{
    t_framebuffer *framebuffer;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite* sprite;
};

void vertex_y(sfRenderWindow *window, sfVector2f **map_2d, int x, int y, int z);
void vertex_x(sfRenderWindow *window, sfVector2f **map_2d, int x, int y, int z);

sfVector2f project_iso_point(int x, int y, int z, mapper mapper);
sfVector2f **create_2d_map(int map[][10], mapper mapper);
sfVertexArray *create_line(sfVector2f *p1, sfVector2f *p2, int z);
int draw_2d_map(sfRenderWindow *window, sfVector2f **two_d_map, int map[][10]);

int test_volume(int map[][10], int y, int x);
//void put_pixel(global global, sf_vector pos, color color);
