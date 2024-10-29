#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * get_card_value - Gets the integer value of a card based on its string value.
 * @value: The string value of the card.
 *
 * Return: The integer value of the card (1 for Ace, 11 for Jack, etc.).
 */
int get_card_value(const char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "Jack") == 0)
		return (11);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "King") == 0)
		return (13);
	return (atoi(value)); /* Converts numbers "2" to "10" */
}

/**
 * compare_cards - Comparison function for qsort.
 * @a: First card node.
 * @b: Second card node.
 *
 * Return: Negative if a < b, positive if a > b, 0 if equal.
 */
int compare_cards(const void *a, const void *b)
{
	deck_node_t *node_a = *(deck_node_t **)a;
	deck_node_t *node_b = *(deck_node_t **)b;

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	return (get_card_value(node_a->card->value) -
			get_card_value(node_b->card->value));
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	deck_node_t *nodes[52];
	int i;

	/* Populate nodes array */
	for (i = 0; i < 52; i++)
	{
		nodes[i] = current;
		current = current->next;
	}

	/* Sort nodes array */
	qsort(nodes, 52, sizeof(deck_node_t *), compare_cards);

	/* Rebuild linked list based on sorted nodes */
	for (i = 0; i < 52; i++)
	{
		nodes[i]->prev = (i > 0) ? nodes[i - 1] : NULL;
		nodes[i]->next = (i < 51) ? nodes[i + 1] : NULL;
	}

	*deck = nodes[0];
}
