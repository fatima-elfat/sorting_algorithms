#include "sort.h"

/**
 * swap - swaps the node ahead or behind.
 * @list: the head of the list of ints.
 * @l1: the tail of the list.
 * @l2: the current swapping node.
 * @st: ahead 1 or behind -1.
 */
void swap(listint_t **list, listint_t **l1, listint_t **l2, int st)
{
	listint_t *tmp;

	if (st == -1)
	{
		tmp = (*l2)->prev;
		if (!((*l2)->next))
			*l1 = tmp;
		else
			(*l2)->next->prev = tmp;
		tmp->next = (*l2)->next;
		(*l2)->prev = tmp->prev;
		if (!(tmp->prev))
			*list = *l2;
		else
			tmp->prev->next = *l2;
		(*l2)->next = tmp;
		tmp->prev = *l2;
		*l2 = tmp;
	}
	else if (st == 1)
	{
		tmp = (*l2)->next;
		if (!((*l2)->prev))
			*list = tmp;
		else
			(*l2)->prev->next = tmp;
		tmp->prev = (*l2)->prev;
		(*l2)->next = tmp->next;
		if (!(tmp->next))
			*l1 = *l2;
		else
			tmp->next->prev = *l2;
		(*l2)->prev = tmp;
		tmp->next = *l2;
		*l2 = tmp;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Cocktail
 * shaker sort algorithm.
 * @list: the head of the list of ints.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *l1, *l2;
	int boo = 0;

	if (!list || !(*list) || !((*list)->next))
		return;
	for (l1 = *list; l1->next;)
		l1 = l1->next;
	while (boo == 0)
	{
		boo = 1;
		for (l2 = l2->prev; l2 != *list; l2 = l2->prev)
		{
			if (l2->n < l2->prev->n)
			{
				boo = 0;
				swap(list, &l1, &l2, -1);
				print_list((const listint_t *)*list);
			}
		}
		for (l2 = *list; l2 != l1; l2 = l2->next)
		{
			if (l2->n > l2->next->n)
			{
				boo = 0;
				swap(list, &l1, &l2, 1);
				print_list((const listint_t *)*list);
			}
		}
	}
}
