/*
** my_putchar.c for my_putchar in /home/woivre_t/mainlib
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Wed Oct  9 07:21:29 2013 Thibault Woivre
** Last update Wed Oct  9 07:22:09 2013 Thibault Woivre
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
