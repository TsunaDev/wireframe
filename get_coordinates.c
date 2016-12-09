/*
** get_coordinates.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec  6 13:31:04 2016 Martin Van Elslande
** Last update Fri Dec  9 21:08:57 2016 Martin Van Elslande
*/

#include	"infog.h"

void	get_number_of_lines_and_rows(int **size, char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n' || buffer[i] == ',')
	{
	  if (buffer[i] == '\n')
	    (*size)[0]++;
	  if ((*size)[0] == 0)
	    (*size)[1]++;
	}
      i++;
    }
  (*size)[0]++;
}

int	*manage_comma_and_n(char *buffer, int *tab)
{
  while (buffer[tab[0]] != ',' && buffer[tab[0]] != '\0' &&
	 buffer[tab[0]] != '\n')
    {
      tab[0]++;
      if (buffer[tab[0] + 1] == '\n')
	{
	  tab[0]++;
	  tab[1]++;
	}
    }
  tab[0]++;
  return (tab);
}

void	coordinates_into_tab(char *buffer, int ***coordinates, int col_num,
			       int lines_num)
{
  int	*tab;
  int	x;

  tab = malloc(sizeof(int) * 3);
  tab[0] = 0;
  x = 0;
  tab[1] = 0;
  if (((*coordinates) = malloc(sizeof(int*) *
			       ((lines_num * col_num) + 1))) == NULL)
    return ;
  while (buffer[tab[0]] != '\0')
    {
      if (((*coordinates)[x] = malloc(sizeof(int) * 4)) == NULL)
	return ;
      if (x != 0)
	(*coordinates)[x][0] = x % col_num;
      (*coordinates)[x][1] = tab[1];
      (*coordinates)[x][2] = my_getnbr(&buffer[tab[0]]);
      x++;
      tab = manage_comma_and_n(buffer, tab);
    }
}

void	get_coordinates(char **av, int ***coordinates, int **size)
{
  int	fd;
  char	*buffer;
  int	bytes;

  if ((buffer = malloc(sizeof(char) * 307201)) == NULL)
    return ;
  if (((*size) = malloc(sizeof(int) * 2)) == NULL)
    return ;
  (*size)[0] = 0;
  (*size)[1] = 0;
  if ((fd = open(av[1], O_RDONLY)) != -1)
    {
      while ((bytes = read(fd, buffer, 307200)) != 0)
	buffer[bytes] = '\0';
      get_number_of_lines_and_rows(size, buffer);
      coordinates_into_tab(buffer, coordinates, (*size)[1], (*size)[0]);
    }
  free(buffer);
}
