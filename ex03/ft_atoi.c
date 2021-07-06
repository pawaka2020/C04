void setsign(int *sign, char c)
{
  if (c == '+')
  {
    *sign *=1;
  }
  else if (c == '-')
  {
    *sign *=-1;
  }
}

void setres(int *res, char c)
{
  int value;

  value = c -'0';
  *res = (*res * 10) + value;
}

int issign(char c)
{
  if ((c == '+') || (c == '-'))
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int isemptyspace(char c){
  if (c == ' ')
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int isnumber(char c){
  if ((c > 47) &&(c < 58))
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int afternumbers(char c, char d, int i)
{
  if (!isnumber(c) && isnumber(d) && i >0 )
  {
    return (1);
  }
  else
  {
    return (0);
  }
}

int ft_atoi(char *str)
{
  int i;
  int sign;
  int res;

  i = 0;
  sign = 1;
  res = 0;
  while (str[i] && i !=-1)
  {
    if (issign(str[i]))
    {
      setsign(&sign, str[i]);
    }
    else if (isnumber(str[i]))
    {
      setres(&res, str[i]);
    }
    else if (afternumbers(str[i], str[i-1], i))
    {
      i = -2;
    }
    i++;
  }
  return (res * sign);
}

// #include <stdio.h>
// int main(void)
// {
// int res = ft_atoi("      ---+--+1234ab567");
// printf("ft_atoi = %d\n", res);
// }
