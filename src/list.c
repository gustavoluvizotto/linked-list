/*
 * list.c
 *
 *  Created on: Apr 9, 2016
 *      Author: gustavo
 */

#include "../inc/list.h"

static void destroy_node(node_t*);
static node_t* create_node(content_t);

void create_list(list_t *list) {
	if (list == NULL) {
		printf("First allocate memory for it");
		return;
	}
	list->head = NULL;
	list->size = 0;
}

void destroy_list(list_t *list) {
	node_t *current = NULL;

	if (list == NULL) {
		printf("Initialize your list.");
		return;
	}

	current = list->head;
	while (current != NULL) {
		list->head = current->next;
		destroy_node(current);
		list->size--;
		current = list->head;
	}
	free(list);
	list = NULL;

	return;
}

node_t* search_element(list_t *list, content_t element) {
	node_t *cur = NULL;
	node_t *_element = NULL;

	if (list == NULL) {
		printf("Initialize your list.");
		return NULL;
	}
	if (list->size == 0) {
		printf("No elements to search\n");
		return NULL;
	}

	_element = create_node(element);

	for (cur = list->head; cur != NULL; cur = cur->next) {
		if (COMP(_element, cur) == 0) {
			destroy_node(_element);
			return cur;
		}
	}

	destroy_node(_element);
	return NULL;
}

static void destroy_node(node_t* node) {
	if (node != NULL) {
		node->next = NULL;
		free(node);
		node = NULL;
	}
	return;
}

static node_t* create_node(content_t element) {
	node_t *node = NULL;

	node = (node_t *) malloc(sizeof(node_t));
	node->content = element;
	node->next = NULL;

	return node;
}

void add_element_in_order(list_t *list, content_t element) {
	node_t *new_element = NULL;
	node_t *cur = NULL;
	node_t *next = NULL;

	if (list == NULL) {
		printf("Initialize your list.");
		return;
	}

	if (search_element(list, element) != NULL) {
		printf("Element exists!");
		return;
	}

	new_element = create_node(element);

	if (list->size == 0) {
		list->head = new_element;
		list->size++;
		return;
	}

	if (COMP(new_element, list->head) < 0) {
		new_element->next = list->head;
		list->head = new_element;
		list->size++;
		return;
	}

	next = list->head->next;
	cur = list->head;
	while (next != NULL && (COMP(next, new_element) < 0)) {
		cur = next;
		next = next->next;
	}
	new_element->next = next;
	cur->next = new_element;
	list->size++;

	return;
}

void print_list(list_t *list) {
	node_t *cur = NULL;

	if (list == NULL) {
		printf("Initialize your list.");
		return;
	}
	for (cur = list->head; cur != NULL; cur = cur->next) {
		print_node(cur);
	}

	return;
}

void print_node(node_t *node) {
	if (node != NULL) {
		printf("%d ", node->content.x);
	}
	return;
}
