/*
** my_getnbr.c for task 6 in /home/martin_v/pool/day4/clone1/CPool_Day04
** 
** Made by Martin Van Elslande
** Login   <martin_v@epitech.net>
** 
** Started on  Thu Oct  6 20:23:55 2016 Martin Van Elslande
** Last update Tue Oct 11 15:43:16 2016 Martin Van Elslande
*/

int	my_isneg(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
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
  int	i;
  int	num;
  int	neg;
  int	nbr;

  i = 0;
  nbr = 0;
  neg = my_isneg(str);
  num = my_isnumber(str, i);
  while (num == 0 || str[i] == '-' || str[i] == '+')
    {    
      if (num == 0)
	{
	  nbr = (10 * nbr) + (str[i] - 48);
	  i++;
	}
      else
        i++;
      num = my_isnumber(str, i);
    }
  nbr = nbr * ((-1) * neg);
  return (nbr);
}
