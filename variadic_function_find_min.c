/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_find_min.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:55:05 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/21 23:26:08 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	variadic_function_find_min(int count, ...)
{
	va_list	args;
	int		i;
	int		min;
	int		keep;

	va_start(args, count);
	i = 0;
	min = 0;
	while (i < count)
	{
		keep = va_arg(args, int);
		if (min > keep)
			min = keep;
		i++;
	}
	return (min);
}

int	main(void)
{
	printf("%d\n", variadic_function_find_min(5, 1, -2, 3, 0, 5));
}
