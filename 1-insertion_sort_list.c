#include "sort.h"

/**
 * insertion_sort_list - sort insert list
 * @list: pointer
 * Return: null
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *F;
		if (!list || !*list || !(*list)->next)
			return;

	F = (*list)->next;
	while (F)
	{
		while (F->prev && F->prev->n > F->n)
		{
		if (F->next)
		F->next->prev = F->prev;
		F->prev->next = F->next;
		F->next = F->prev;
		F->prev = F->prev->prev;
		F->next->prev = F;
		if (!(F->prev))
			*list = F;
		else
			F->prev->next = F;
		print_list(*list);
		}
		F = F->next;
	}
}
