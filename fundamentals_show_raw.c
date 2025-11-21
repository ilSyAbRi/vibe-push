/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamentals_show_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:09:26 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/21 19:11:18 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	fundamentals_show_raw(int x,float k, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args,k);
	
	printf("%d\n", args->fp_offset);
	printf("%d\n", args->gp_offset);
	printf("%d\n",*(int *)(args->overflow_arg_area));
	printf("%d\n",*(int *)(args->reg_save_area + 16));
}

int main()
{
	fundamentals_show_raw(5,5.5,20,30,40,20);
}
