/*
** my_putstr.c for my_putstr in /home/woivre_t/rendu/Piscine-C-Jour_04
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Thu Oct  3 09:53:19 2013 Thibault Woivre
** Last update Tue Oct 15 16:45:33 2013 Thibault Woivre
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
