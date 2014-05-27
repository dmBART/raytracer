/*
** my_put_nbr.c for my_put_nbr in /home/woivre_t/rendu/Piscine-C-Jour_03
** 
** Made by Thibault Woivre
** Login   <woivre_t@epitech.net>
** 
** Started on  Wed Oct  2 16:48:25 2013 Thibault Woivre
** Last update Sun Nov 17 21:20:28 2013 Thibault Woivre
*/

int	my_put_nbr(int nb)
{
  if (nb != -2147483648)
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = -nb;
	}
      boucle(nb);
    }
  else
    {
      my_putchar('-');
      my_putchar('2');
      my_putchar('1');
      my_putchar('4');
      my_putchar('7');
      my_putchar('4');
      my_putchar('8');
      my_putchar('3');
      my_putchar('6');
      my_putchar('4');
      my_putchar('8');
    }
  return (0);
}

int	boucle(int nb)
{
  int	test;
  int	puissance;

  test = 0;
  puissance = 1000000000;
  while (puissance >= 1)
    {
      if (nb / puissance != 0)
	{
	  test = 1;
	}
      if (test == 1)
	{
	  my_putchar(nb / puissance + 48);
	  nb = nb - puissance * (nb / puissance);
	}
      puissance = puissance / 10;
    }
  if (test == 0)
    {
      my_putchar(48);
    }
  return (0);
}
