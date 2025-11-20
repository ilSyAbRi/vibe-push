/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_Debug_Utility_for_Arrays.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:22:54 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 19:43:37 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_print(int *arr, int len)
{
	int	i;
	int	first;

	first = 1;
	i = 0;
	while (i < len)
	{
		if (first == 0)
			ft_putchar(' ');
		ft_putnbr(arr[i]);
		first = 0;
		i++;
	}
}

void	debug_arrays(int count, ...)
{
	int		i;
	int		*arr;
	int		len;
	va_list	args;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		arr = va_arg(args, int *);
		len = va_arg(args, int);
		ft_print(arr, len);
		ft_putchar('\n');
		i++;
	}
	va_end(args);
}

int	main(void)
{
	int	arr1[4] = {1, 2, 3, 4};
	int	arr2[6] = {10, 20, 30, 40, 50, 60};

	debug_arrays(2, arr1, 4, arr2, 6);
}
