/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** test_volume
*/

int test_volume(int map[][10], int y, int x)
{
    int volume = 0;

    if (map[y][x] < -5 || map[y + 1][x] < -5 || map[y][x + 1] < -5)
        volume = 2;
    else if (map[y][x] > 5 || map[y][x + 1] > 5 || map[y + 1][x] > 5)
        volume = 1;
    return (volume);
}