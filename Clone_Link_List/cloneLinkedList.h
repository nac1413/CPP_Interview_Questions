#pragma once
#include<iostream>

class Node
{
public:
	int data;
	Node* next;
	Node* arb;
	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->arb = NULL;
	}
};

void insertAtBegin(Node*& head, int d) {
	Node* newNode = new Node(d);
	newNode->next = head;
	newNode->arb = NULL;
	head = newNode;
}

void display_using_next(Node* head) {
	std::cout << std::endl;
	while (head) {
		std::cout << head->data<<" ";
		head = head->next;
	}
	std::cout << std::endl;
}

void display_using_arb(Node* head) {
	Node* ptr = head;
	std::cout << std::endl;
	while (ptr) {
		if (ptr->arb)
			std::cout << ptr->data << " -> " << ptr->arb->data << std::endl;
		else
			std::cout << ptr->data << " NULL " << std::endl;
		ptr = ptr->next;
	}
}

void insertAtEnd(Node*& head, int d) {
	Node* ptr = head;
	while (ptr->next) {
		ptr = ptr->next;
	}
	Node* temp = new Node(d);
	ptr->next = temp;
	ptr = temp;
}

void insertAtPos(Node*& head, int data, int pos) {
	if (pos < 1) {
		std::cout << "position should be +ve number." << std::endl;
		return;
	}
	int i = 2;
	Node* ptr = head;
	while (i <= pos) {
		if (i == pos && ptr->next != NULL) {
			Node* tmp = new Node(data);
			tmp->next = ptr->next;
			ptr->next = tmp;
		}
		i++;

		ptr = ptr->next;
	}
}