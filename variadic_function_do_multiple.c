/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_do_multiple.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:27:30 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/21 23:35:01 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	variadic_function_do_multiple(int count, ...)
{
	int		multiple;
	va_list	args;
	int		i;

	i = 0;
	multiple = 1;
	va_start(args, count);
	while (i < count)
	{
		multiple = multiple * va_arg(args, int);
		i++;
	}
	return (multiple);
}

int	main(void)
{
	printf("%d\n", variadic_function_do_multiple(5, 1, 2, 3, 4, 5));
}
