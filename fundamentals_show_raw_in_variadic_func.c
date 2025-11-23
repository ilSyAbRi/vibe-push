/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamentals_show_raw_in_variadic_func.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:09:26 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/23 18:16:09 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	fundamentals_show_raw_in_variadic_func(double c ,float x, ...)
{
	int	i;
	va_list args;

	i = 0;
	
	printf("%d\n",args->fp_offset);// no
	printf("%d\n",args->gp_offset);// no 
	
	va_start(args,c);
	
	printf("%d\n",args->fp_offset);// 48
	printf("%d\n",args->gp_offset);// 24 || 16

	//printf("%d\n",*(int *)args->reg_save_area + args->gp_offset);//8  random number
	//printf("%d\n",*(int *)args->overflow_arg_area);//60 60
}

int main()
{
	fundamentals_show_raw_in_variadic_func(5,10,20,30,40,50,60,70);
}
