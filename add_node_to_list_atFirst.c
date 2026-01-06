#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
	int				val;
	struct nodes	*next;
}					t_nodes;

t_nodes	*add_node(t_nodes *head, int nb)
{
	t_nodes	*new_node;
	t_nodes	*current;

	new_node = malloc(sizeof(t_nodes));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->val = nb;
	if (head == NULL)
		return (new_node);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (head);
}

t_nodes	*create_nodes_list(int max)
{
	t_nodes	*head;
	int		nb;
	int		i;

	head = NULL;
	i = 0;
	while (i < max)
	{
		printf("entre the number you want to add to list at this node : ");
		scanf("%d", &nb);
		head = add_node(head, nb);
		if (head == NULL)
			return (NULL);
		printf("\n");
		i++;
	}
	return (head);
}

void	print_list(t_nodes *head)
{
	printf("the full list we have is \n");
	while (head != NULL)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

void	addfront_list(t_nodes **head, int nb)
{
	t_nodes * new_node;
	new_node = malloc(sizeof(t_nodes));
			if (new_node == NULL)
				return ;
	new_node->val = nb;
	new_node->next = *head;
	*head = new_node;
}

int	main(void)
{
	int		x;
	t_nodes	*list;

	printf("how many number you want add to list : ");
	scanf("%d", &x);
	printf("\n");
	list = create_nodes_list(x);
	print_list(list);
	printf("the element you want to add to the first of the list : ");
	scanf("%d", &x);
	addfront_list(&list,x);
	print_list(list);
}

