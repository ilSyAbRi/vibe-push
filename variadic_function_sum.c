/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_sum.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:34:49 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 15:38:44 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_do_sum(int count , ...)
{
	va_list args;
	va_start(args,count);

	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < count)
	{
		sum = sum + va_arg(args,int);
	i++;
	}
	return sum;
}

int main()
{
	printf("%d\n",ft_do_sum(5,10,10,10,10,10));
}
