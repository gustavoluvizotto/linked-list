/*
 * list.h
 *
 *  Created on: Apr 8, 2016
 *      Author: gustavo
 */

#ifndef INC_LIST_H_
#define INC_LIST_H_

#include "common.h"

typedef struct content_s {
	int32_t x;
} content_t;

typedef struct node_s {
	content_t content;
	struct node_s *next;
} node_t;

typedef struct list_s {
	node_t *head;
	uint32_t size;
} list_t;

void print_list(list_t*);
void print_node(node_t*);
node_t* search_element(list_t*, content_t);
void add_element_in_order(list_t*, content_t);
void create_list(list_t*);
void destroy_list(list_t*);

#endif /* INC_LIST_H_ */
