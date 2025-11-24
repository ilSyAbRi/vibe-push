/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function_find_max.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:39:40 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/24 22:46:14 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	*variadic_function_find_max(int count, ...)
{
	int		i;
	va_list	args;
	int		*max;
	int		keep;

	i = 1;
	va_start(args, count);
	if (count == 0)
		return (NULL);
	max = malloc(sizeof(int));
	if (max == NULL)
		return (NULL);
	*max = va_arg(args, int);
	while (i < count)
	{
		keep = va_arg(args, int);
		if (*max < keep)
			*max = keep;
		i++;
	}
	return ((void *)max);
}

int	main(void)
{
	int	*nb;

	nb = variadic_function_find_max(5, 3, 3, 5, 6, 1);
	if (nb == NULL)
		return (1);
	else
		printf("%d\n", *nb);
	free(nb);
	nb = NULL;
	return (0);
}
