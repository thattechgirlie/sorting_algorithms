#include "deck.h"
/**
 * sort_deck - sorting deck of cards
 * @deck: head pointer of double linked list *
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
