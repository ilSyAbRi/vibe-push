/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:35:13 by ilsyabri          #+#    #+#             */
/*   Updated: 2025/11/30 14:38:38 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int	fd = open("test.txt",O_RDONLY);
	char	buf[5];
	int	r = read(fd, buf, 4);

	buf[r] = '\0';
	printf("READ: %s\n",buf);
}
