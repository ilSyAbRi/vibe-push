/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_log_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:05:44 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 18:53:39 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

#define INFO 1
#define SUCCESS 2
#define WARNING 3

void	check_level(int level)
{
	if (level == INFO)
		ft_putstr("[INFO] ");
	else if (level == SUCCESS)
		ft_putstr("[SUCCESS] ");
	else if (level == WARNING)
		ft_putstr("[WARNING] ");
}

void	variadic_log_msg(int level, const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	check_level(level);
	while (format[i] != 0)
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			if (format[i + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i + 1] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (format[i + 1] == '%')
				ft_putchar('%');
			else
				ft_putchar(format[i]);
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
}

/*int	main(void)
{
	variadic_log_msg(INFO, "User %s logged in cluster at %d\n", "ilsyabri", 10);
	variadic_log_msg(SUCCESS, "PASS ALL TEST of %s\n", "ft_printf");
	variadic_log_msg(WARNING, "Memory usage is %d%%\n", 85);
}*/
