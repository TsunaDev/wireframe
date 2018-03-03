/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** functions to get the coordinates
*/

#include	"infog.h"

void	get_number_of_lines_and_rows(int **size, char *buffer)
{
	int	i = 0;

	while (buffer[i] != '\0' || (buffer[i] == '\n' &&
				buffer[i + 1] != '\n')) {
		if (buffer[i] == '\n' || buffer[i] == ',') {
			if (buffer[i] == '\n' && (buffer[i + 1] != '\0' &&
						buffer[i + 1] != '\n' &&
						buffer[i - 1] != '\n'))
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
	buffer[tab[0]] != '\n') {
		tab[0]++;
		if (buffer[tab[0] + 1] == '\n' && tab[0] != '\n') {
			tab[0]++;
			tab[1]++;
		}
	}
	tab[0]++;
	return (tab);
}

void	coordinates_into_tab(char *buffer, int ***coordinates, int c_num,
			int l_num)
{
	int	*tab = malloc(sizeof(int) * 3);
	int	x = 0;

	if (tab) {
		tab[0] = 0;
		tab[1] = 0;
		*coordinates = malloc(sizeof(int *) * ((l_num * c_num) + 1));
		if (!(*coordinates))
			return ;
		while (buffer[tab[0]] != '\0') {
			(*coordinates)[x] = malloc(sizeof(int) * 4);
			if (x != 0)
				(*coordinates)[x][0] = x % c_num;
			(*coordinates)[x][1] = tab[1];
			(*coordinates)[x][2] = my_getnbr(&buffer[tab[0]]);
			x++;
			tab = manage_comma_and_n(buffer, tab);
		}
		free(tab);
	}
}

int	manage_input(char *str)
{
	int	fd = open(str, O_DIRECTORY);

	if (fd == -1)
		return (0);
	else {
		close(fd);
		return (-1);
	}
}

int	get_coordinates(char **av, int ***coordinates, int **size)
{
	int	fd;
	char	buffer[100000];
	int	bytes;

	if (((*size) = malloc(sizeof(int) * 2)) == NULL)
		return (-1);
	(*size)[0] = 0;
	(*size)[1] = 0;
	if (manage_input(av[1]) == -1)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) != -1)	{
		while ((bytes = read(fd, buffer, 307200)) != 0)
			buffer[bytes] = '\0';
		get_number_of_lines_and_rows(size, buffer);
		coordinates_into_tab(buffer, coordinates, (*size)[1],
				(*size)[0]);
	} else
		return (-1);
	close(fd);
	return (0);
}
