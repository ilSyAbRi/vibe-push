/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_log_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:05:44 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 18:26:36 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
	i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb ==  -2147483648)
	{
		write(1,"-2147483648",11);
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
#define ERROR 2
#define WARNING 3

void	variadic_log_msg(int level, const char *format, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args,format);
	if (level == INFO)
		ft_putstr("[INFO] ");
	else if (level == ERROR)
		ft_putstr("[ERROR] ");
	else if (level == WARNING)
		ft_putstr("[WARNING] ");
	while (format[i] != 0)
	{
		if (format[i] == '%' && i != '\0')
		{
			if (format[i + 1]  == 's')
				ft_putstr(va_arg(args,char *));
			else if (format[i + 1] == 'd')
				ft_putnbr(va_arg(args,int));
			else
				ft_putchar(format[i]);
		}
		else
			ft_putchar(format[i]);
	i++;
	}
}

int main()
{
	variadic_log_msg(INFO, "User %s logged in at %d\n", "john", 10);
	variadic_log_msg(ERROR, "Failed to open file %s\n", "data.txt");
	variadic_log_msg(WARNING, "Memory usage is %d%%\n", 85);
}
