#include "../inc/list.h"

int main(void) {
	list_t *list = NULL;
	content_t content;
	node_t *x = NULL;

	list = (list_t *) malloc(sizeof(list_t));
	create_list(list);

	content.x = 3;
	add_element_in_order(list, content);

	content.x = 4;
	add_element_in_order(list, content);

	content.x = 1;
	add_element_in_order(list, content);

	content.x = 7;
	add_element_in_order(list, content);

	content.x = 0;
	add_element_in_order(list, content);

	print_list(list);

	x = search_element(list, content);
	print_node(x);

	destroy_list(list);
	return 0;
}
