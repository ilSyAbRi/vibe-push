/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_find_min.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:55:05 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/24 22:41:15 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*variadic_function_find_min(int count, ...)
{
	va_list	args;
	int		i;
	int		*min;
	int		keep;

	va_start(args, count);
	if (count == 0)
		return (NULL);
	min = malloc(sizeof(int));
	if (min == NULL)
		return (NULL);
	i = 1;
	*min = va_arg(args, int);
	while (i < count)
	{
		keep = va_arg(args, int);
		if (*min > keep)
			*min = keep;
		i++;
	}
	return ((void *)min);
}

int	main(void)
{
	int	*nb;

	nb = variadic_function_find_min(5, 1, -2, 3, 0, 5);
	if (nb == NULL)
		return (1);
	else
		printf("%d\n", *nb);
	free(nb);
	nb = NULL;
	return (0);
}
