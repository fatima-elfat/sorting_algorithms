#include "sort.h"

/**
 * checkn - ...
 * @ptr: ...
*/
void checkn(listint_t *ptr)
{
	if (ptr->next)
		ptr->next->prev = ptr->prev;
}
/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers in ascending order using the Insertion sort algorithm.
 * @list: ...
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *next, *ptr;

	if (!list || !(*list) || !((*list)->next))
		return;
	cur = (*list)->next;
	next = cur->next;
	while (cur)
	{
		if (cur->n < cur->prev->n)
		{
			ptr = cur->prev;
			while (ptr && (cur->n < ptr->n))
			{
				if (ptr->prev)
				{
					cur->prev->next = cur->next;
					checkn(cur);
					ptr->prev->next = cur;
					cur->prev = ptr->prev;
					ptr->prev = cur;
					cur->next = ptr;
				}
				else
				{
					ptr->prev = cur;
					cur->prev->next = cur->next;
					checkn(cur);
					cur->prev = NULL;
					cur->next = ptr;
					*list = cur;
				}
				print_list(*list);
				ptr = cur->prev;
			}
		}
		cur = next;
		next = NULL;
		if (cur)
			next = cur->next;
	}
}
