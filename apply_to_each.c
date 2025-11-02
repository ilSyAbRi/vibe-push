
#include <stdio.h>

int	double_it(int	nb)
{
	nb = nb * 2;
	return nb;
}

int	square_it(int nb)
{
	nb = nb * nb;
	return nb;
}

void	apply_to_each(int *arr, int size, int (*f)(int))
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = f(arr[i]);
	i++;
	}
}

int	main()
{
	int	arr[] = {1,2,3,4,5,6};
	int	size = 6;
	int	i;

	i = 0;
	//apply_to_each(arr,size,&double_it);
	apply_to_each(arr,size,square_it);
	while (i < size)
	{
		printf("%d\n",arr[i]);
	i++;
	}
}
