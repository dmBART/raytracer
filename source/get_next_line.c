/*
** get_next_line.c for get_next_line in /home/woivre_t/rendu/get_next_line-2017-woivre_t
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Mon Nov 18 10:58:45 2013 Thibault Woivre
** Last update Mon Mar 10 18:40:50 2014 Thibault Woivre
*/

#include	"../mlxwin.h"
#include	"get_next_line.h"

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER_SIZE];
  static int	i = 0;
  static int	k = 0;
  static int	flag = 0;

  if (flag == 0)
    {
      k = read(fd, buffer, BUFFER_SIZE);
      flag = 1;
    }
  if (k == -1)
    return (NULL);
  return (creat_str(&flag, &i, &k, buffer));
}

char		*creat_str(int *flag, int *i, int *k, char *buffer)
{
  int		j;
  char		*str;

  j = 0;
  while (*i + j != *k && (buffer[*i + j] != '\n' && buffer[*i + j] != '\0'))
    j++;
  if (j == 0 && *i + j == *k)
    {
      *i = 0;
      *flag = 0;
      return (NULL);
    }
  else
    str = xmalloc(j + 1);
  j = 0;
  while (*i != *k && buffer[*i] != '\n' && buffer[*i] != '\0')
    {
      str[j] = buffer[*i];
      *i = *i + 1;
      j++;
    }
  str[j] = 0;
  buffer[*i] == '\n' ? *i = *i + 1 : 1;
  return (str);
}
