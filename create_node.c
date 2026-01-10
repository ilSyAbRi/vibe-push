/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsyabri <ilsyabri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:42:00 by ilsyabri          #+#    #+#             */
/*   Updated: 2026/01/10 15:25:20 by ilsyabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct nodes{
	int	val;
	struct nodes *next;
} t_node;

t_node *create_node(int val)
{
	t_node *new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return NULL;
	new_node->val = val;
	new_node->next = NULL;

	return new_node;
}

void	print_nodes(t_node *head)
{
	while (head != NULL)
	{
		printf("%d\n",head->val);
		head = head->next;
	}
}

int main()
{
	t_node *new_node;
	t_node *head;
	t_node *current;
	int	i;
	int	val;

	i = 0;
	val = 1;
	head = NULL;
	while (i < 3)
	{
		new_node = create_node(val);
			if (new_node == NULL)
				return 1;
			
			if (head == NULL)
				head = new_node;
			else
				current->next = new_node;
			current = new_node;
	val++;
	i++;
	}
	print_nodes(head);
}
