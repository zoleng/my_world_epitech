/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** click
*/

int **change_map(int x, int y, int **map, int valeur)
{
    if (valeur == 1)
        map[y][x] =+ 1;
    else if (valeur == 0)
        map[y][x] =- 1;
    update_map (map);
}

void update_map()
{

}
