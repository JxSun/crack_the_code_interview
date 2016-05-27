#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
	int value;
	struct node_struct *next;
} node;

node* create_test_list()
{
	int data[] = { 2, 4, 6, 8, 4, 6, 6, 2, 1, 8 };
	node *head = NULL, *prev = NULL;
	int i;
	for (i = 0; i < 10; i++) {
		node *n = (node *)malloc(sizeof(node));
		n->value = data[i];
		if (i == 0) {
			head = n;
		} else {
			prev->next = n;
		}
		prev = n;
	}
	prev->next = NULL;
	return head;
}

void print_list(node *n)
{
	if (!n) return;

	node *tmp = n;
	while (tmp) {
		printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

/**
 * Space: O(n)
 * Time: O(n)
 */
/*
void remove_duplicates(node *n)
{
	hash_table table; // suppose I have a hash table instance
	node *curr = n, *prev;
	for (; curr; prev = curr, curr = curr->next) {
		if (table.get(curr->value)) {
			prev->next = curr->next;
			free(curr);
			curr = prev;
		} else {
			table.put(curr->value)
		}
	}
}
*/

/**
 * Space: O(1)
 * Time: O(n^2)
 */
void remove_duplicates_no_extra_space(node *n)
{
	node *curr = n;
	for (; curr; curr = curr->next) {
		node *runner = curr;
		while (runner->next) {
			if (runner->next->value == curr->value) {
				node *tmp = runner->next->next;
				free(runner->next);
				runner->next = tmp;
			} else {
				runner = runner->next;
			}
		}	
	}
}

void free_list(node *n)
{
	while (n) {
		node *tmp = n->next;
		free(n);
		n = tmp;
	}
}

int main()
{
	node *head = create_test_list();
	print_list(head);
	remove_duplicates_no_extra_space(head);
	print_list(head);
	free_list(head);
	return 0;
}
