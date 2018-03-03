/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** the good old getnbr
*/

int	my_isneg(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && str[i] != ',' && str[i] != '\n') {
		if (str[i] == '-')
			n++;
		i++;
	}
	if (n % 2 == 0)
		return (-1);
	else
		return (1);
}

int	my_isnumber(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	else
		return (1);
}

int	my_getnbr(char *str)
{
	int	i = 0;
	int	nbr = 0;
	int	neg = my_isneg(str);
	int	num = my_isnumber(str, i);

	while (num == 0 || str[i] == '-' || str[i] == '+') {
		if (num == 0) {
			nbr = (10 * nbr) + (str[i] - 48);
			i++;
		} else
			i++;
		num = my_isnumber(str, i);
	}
	nbr = nbr * ((-1) * neg);
	return (nbr);
}
