/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_find_max.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:39:40 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 15:51:09 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	variadic_function_find_max(int count, ...)
{
	int		i;
	va_list	args;
	int		max;
	int		keep;

	i = 0;
	va_start(args, count);
	max = 0;
	while (i < count)
	{
		keep = va_arg(args, int);
		if (max < keep)
			max = keep;
		i++;
	}
	return (max);
}

int	main(void)
{
	printf("%d\n", variadic_function_find_max(5, 3, 3, 5, 6, 1));
}
