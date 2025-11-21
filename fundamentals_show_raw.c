/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamentals_show_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:09:26 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/21 18:35:18 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	fundamentals_show_raw(int x, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args,x);
	
	printf("%d\n",(int*)args->fp_offset);
	printf("%d\n",(int*)args->gp_offset);
	printf("%d\n",(int*)args->overflow_arg_area);
	printf("%d\n",(int*)args->reg_save_area);
}

int main()
{
	fundamentals_show_raw(4,10,20,30,40);
}
