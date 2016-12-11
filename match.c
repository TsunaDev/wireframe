/*
** match.c for match in /home/martin_v/pool/match/clone/CPool_match-nmatch
** 
** Made by Martin Van Elslande
** Login   <martin_v@epitech.net>
** 
** Started on  Sun Oct 16 18:05:19 2016 Martin Van Elslande
** Last update Sun Dec 11 19:04:50 2016 Martin Van Elslande
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
  int	i;
  int	j;

  i = 0;
  j = i;
  while ((s1[i] != '\0' && s1[i] == s2[j]) || s2[j] == '*')
    {
      if (s2[j] == '*')
	{
	  while (s2[j + 1] == '*')
	    j++;
	  j++;
	  i = loop(j, i, s1, s2);
	}
      else
	{
	  i++;
	  j++;
	}
    }
  if (i == my_strlen(s1))
    return (1);
  else
    return (0);
}
