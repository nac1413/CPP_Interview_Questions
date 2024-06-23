#include"cloneLinkedList.h"

int main() {
	Node* head = new Node(5);
	insertAtBegin(head, 4);
	insertAtBegin(head, 3);
	insertAtBegin(head, 2);
	insertAtBegin(head, 1);
	display_using_next(head);
	head->arb = head->next->next;
	head->next->arb = head->next->next->next;
	head->next->next->arb = head;
	head->next->next->next->arb = head->next;
	head->next->next->next->next->arb = head->next->next;
	display_using_arb(head);


	/*First stage of clone; Insert duplicate nodes
	eg -> list = 1 -> 2 -> 3 -> 4 -> 5 -> NULL
	inserted list = 1 -> 1-> 2 -> 2 ->3 -> 3 -> 4 -> 4 -> 5 -> 5 -> NULL*/
	Node* ptr = head;
	if (head->next) {
		int pos = 2;
		while (ptr->next) {
			insertAtPos(head, ptr->data, pos);
			pos += 2;
			ptr = ptr->next->next;
		}
	}
	insertAtEnd(head, ptr->data);
	display_using_next(head);
	display_using_arb(head);


	//Copy the arb value for inserted element too
	Node* tmp = head;
	while (tmp) {
		if (tmp->arb != NULL)
			tmp->next->arb = tmp->arb->next;
		else
			tmp->next->arb = NULL;
		tmp = tmp->next->next;
	}

	display_using_arb(head);

	//seperate original and clone
	Node* org_head = head;
	Node* clone_head = NULL;
	clone_head = head->next;
	Node* ptr_clone = clone_head;
	while (org_head && org_head->next) {
		org_head->next = ptr_clone->next;
		if (ptr_clone->next)
			ptr_clone->next = ptr_clone->next->next;
		else
			ptr_clone->next = NULL;
		org_head = org_head->next;

		ptr_clone = ptr_clone->next;
	}

	display_using_arb(head);
	display_using_arb(clone_head);
	return 0;

}