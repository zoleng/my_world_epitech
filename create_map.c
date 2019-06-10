/*
** EPITECH PROJECT, 2019
** MUL_my_world_2018
** File description:
** create_map
*/

#include <stdlib.h>

int print_board(int **map)
{
    for (int j = 0; j != 10; j++) {
        for (int i = 0; i != 10; i++)
            my_put_nbr(map[j][i]);
        my_putchar('\n');
    }
    return (0);
}

/*int **malloc_line(int **map)
{
    int column = 10;
    int i = 0;
    int line = 10;

    map = malloc(sizeof(int *) * line);
    while (i != line) {
        map[i] = malloc(sizeof(int) * column);
        i = i + 1;
    }
    for (int j = 0; j != 10; j++) {
        for (int i = 0; i != 10; i++) {
            map[j][i] = i;
        }
    }
    return (map);
}*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

int	my_put_nbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
          nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}

int **create_map(int **map, int *input_file)
{
    int x = 0;

    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
          map[j][i] = input_file[x];
            x++;
        }
    }
    print_board(map);
    return (map);
}