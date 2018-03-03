/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** string match function
*/

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	loop(int j, int i, char *s1, char *s2)
{
	while (s2[j] != s1[i])
	{
		if (s1[i] == '\0')
			return (1);
		else
			i++;
	}
	return (i);
}

int	match(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while ((s1[i] != '\0' && s1[i] == s2[j]) || s2[j] == '*') {
		if (s2[j] == '*') {
			while (s2[j + 1] == '*')
				j++;
			j++;
			i = loop(j, i, s1, s2);
		} else {
			i++;
			j++;
		}
	}
	if (i == my_strlen(s1))
		return (1);
	else
		return (0);
}
