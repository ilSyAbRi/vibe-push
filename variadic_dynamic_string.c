/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_dynamic_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:35:20 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/20 17:10:29 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_len_of_variadic_function(int count, va_list *list)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < count)
	{
		len = len + ft_strlen(va_arg(*list, char *));
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*concat(int count, ...)
{
	int		i;
	int		len;
	char	*str;
	char	*arr;
	va_list	args;

	i = 0;
	va_start(args, count);
	len = count_len_of_variadic_function(count, &args);
	arr = malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	va_end(args);
	va_start(args, count);
	arr[0] = '\0';
	while (i < count)
	{
		str = va_arg(args, char *);
		arr = ft_strcat(arr, str);
		i++;
	}
	va_end(args);
	return (arr);
}

int	main(void)
{
	printf("%s\n", concat(3, "hello ", "dear ", "world"));
}
