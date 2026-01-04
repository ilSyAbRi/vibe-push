#include <stdio.h>
#include <stdlib.h>

typedef struct nodes{
	int	val;
	struct nodes * next;
}t_nodes;

t_nodes *create_node_list(void)
{
	t_nodes *head = malloc(sizeof(t_nodes));
	if (head == NULL)
		return NULL;
	head->val = 1;

	head->next = malloc(sizeof(t_nodes));
	if (head->next == NULL)
		return NULL;
	head->next->val = 2;

	head->next->next = malloc(sizeof(t_nodes));
	if (head->next->next == NULL)
		return NULL;
	head->next->next->val = 3;

	head->next->next->next = malloc(sizeof(t_nodes));
	if (head->next->next->next == NULL)
		return NULL;
	head->next->next->next->val =4;

	head->next->next->next->next = NULL;
	return head;
}

void	print_list(t_nodes *head)
{
	t_nodes	* current = head;

	while (current != NULL)
	{
		printf("%d\n",current->val);
		current = current->next;
	}
}

t_nodes *	add_node(t_nodes *head,int nb)
{
	t_nodes *current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = malloc(sizeof(t_nodes));
	if (current->next == NULL)
		return NULL;
	current->next->val = nb;
	current->next->next = NULL;

	return head;
}

int main()
{
	t_nodes * result = create_node_list();
	result = add_node(result,5);
	if (result == NULL)
		return 1;
	print_list(result);
}

