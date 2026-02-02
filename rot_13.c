#include <unistd.h>

int is_bet_m_z(char c)
{
	if ((c >= 'm'  && c <= 'z') || (c >= 'M' && c <= 'Z'))
		return 1;
	return 0;
}

int	is_bet_a_n( char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		return 1;
	return 0;
}

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	main(int argc, char *argv[])
{
	if(argc == 2)
	{
		int	i;

		i = 0;
		while (argv[1][i])
		{
			if (is_bet_a_n(argv[1][i]))
				ft_putchar(argv[1][i] + 13);
			else if (is_bet_m_z(argv[1][i]))
				ft_putchar(argv[1][i] - 13);
			else
				ft_putchar(argv[1][i]);
		i++;
		}
	}
	write(1, "\n", 1);
}
