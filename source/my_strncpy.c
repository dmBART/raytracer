/*
** my_strncpy.c for my_strncpy in /home/woivre_t/rendu/Piscine-C-Jour_06/ex_2
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Mon Oct  7 11:28:26 2013 Thibault Woivre
** Last update Sat Mar  8 13:59:57 2014 Thibault Woivre
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
