/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_average_offloat.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:09:32 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 16:27:29 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

float	variadic_function_average_floating_point(int count, ...)
{
	int		i;
	float	sum;
	va_list	args;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		sum = sum + va_arg(args, double);
		i++;
	}
	return (sum / count);
}

int	main(void)
{
	printf("%.2f\n", variadic_function_average_floating_point(3, 2.5, 7.0,
			9.5));
}
