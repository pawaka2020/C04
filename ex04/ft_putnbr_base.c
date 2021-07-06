#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void  getbaselen(int *baselen, char *str)
{
	*baselen = 0;
	while (str[*baselen])
	{
		*baselen = *baselen + 1;
	}
}

void  setsign2(char *sign, int *nbr)
{
 if (*nbr < 0)
  {
    *sign = '-';
    *nbr = *nbr * -1;
  }
  else
  {
    *sign = '\0';
    *nbr = *nbr * 1;
  }
}

void printoutput(int i, char *base, int* conv_nbr, int sign)
{
  char result;

  if (sign == '-')
  {
    ft_putchar(sign);
  }
  while(i>=0)
  {
    result = base[conv_nbr[i]];
	  ft_putchar(result);
    i--;
  }
}

void setconv_nbr(int *i, int *nbr, int baselen, int *conv_nbr)
{
  *i = 0;
  while (*nbr !=0)
  {
    conv_nbr[*i] = *nbr % baselen;
    *nbr = *nbr / baselen;
    *i = *i + 1;
  }
}

int samechars(char *base, int baselen)
{
  int result;
  int i;
  int j;

  result = 1;
  i = -1;
  j = -1;
  while (i++, i < baselen)
  {
    while (j++, j < baselen)
    {
      if ((base[i] == base [j]) && (i !=j))
      {
        result = result * 0;
      }
      else
      {
        result = result * 1;
      }
    }
    j = 0;
  }
  return (result);
}

int plusminus (char *base, int baselen)
{
  int result; 
  int i;

  result = 1;
  i = -1;
  while (i++, i < baselen)
  {
    if ((base[i] == '+') || (base[i] == '-'))
    {
      result = result * 0; 
    }
    else
    {
      result = result * 1;
    }
  }
  return (result);
}

int invalidbase(char *base, int baselen)
{
  if (baselen < 2)
  {
    return (1);
  }
  else if (!samechars(base, baselen))
  {
    return (1);
  }
  else if (!plusminus(base, baselen))
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

void	ft_putnbr_base(int nbr, char *base)
{
  char sign;
  int i;
  int baselen;

  getbaselen(&baselen, base);
  if (!invalidbase(base, baselen))
  {
    int conv_nbr[baselen * 30];

    setsign2(&sign, &nbr);
    setconv_nbr(&i, &nbr, baselen, conv_nbr);
    printoutput(i-1, base, conv_nbr, sign);
  }
}

//#include <stdio.h>
// int main(void)
// {
//   ft_putnbr_base(987654321, "0123456789");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "01");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "0123456789ABCDEF");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "poneyvif");
//   ft_putchar('\n');
//   ft_putnbr_base(-987654321, "poneyvif");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "ggwp");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "+-");
//   ft_putchar('\n');
//   ft_putnbr_base(987654321, "0123456789");
//   ft_putchar('\n');
// }