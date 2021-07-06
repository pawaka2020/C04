#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_l;
	char	nbr_c[32];
	int		base_divider;
	int		i;

	if (!ft_check_base(base))
		return ;
	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-');
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr_c[i]);
}

int main(void)
{
  ft_putnbr_base(987654321, "0123456789");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "01");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "0123456789ABCDEF");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "poneyvif");
  ft_putchar('\n');
  ft_putnbr_base(-987654321, "poneyvif");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "ggwp");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "+-");
  ft_putchar('\n');
  ft_putnbr_base(987654321, "0123456789");
  ft_putchar('\n');
}