#include "sort.h"

/**
* Swap - a simple swap
* @array1: position one
* @array2: position two
* Return - VOID
*/
void Swap(int *array1, int *array2)
{
	int xyz;

	xyz = *array1;
	*array1 = *array2;
	*array2 = xyz;
}


/**
* hi_lo - takes in an array, hi_lo okc
* @array: the array
* @lo: low pos
* @hi: high pos
* @size: array size
* Return: i + 1
*/
int hi_lo(int *array, int lo, int hi, size_t size)
{
	int x;
	int i;
	int j;

	x = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < x)
		{
			i += 1;
			Swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
	Swap(&array[i + 1], &array[hi]);
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}


/**
* quickie - lit
* @array: an array
* @lo: low index
* @hi: upper index
* @size: the size
* Return: NULL
*/

void quickie(int *array, int lo, int hi, size_t size)
{
	int i;

	if (lo < hi)
	{
		i = hi_lo(array, lo, hi, size);
		quickie(array, lo, i - 1, size);
		quickie(array, i + 1, hi, size);
	}
}


/**
* quick_sort - sorts array
* @array: the array
* @size: size
* Return: NULL
*/

void quick_sort(int *array, size_t size)
{
	int flag = 0;
	size_t temp = 0;

	if (!array || size < 2)
		return;

	while (temp < size - 1)
	{
		if (array[temp] != array[temp + 1])
			flag = 1;
		temp++;
	}

	if (flag == 1)
		quickie(array, 0, size - 1, size);
}
