#ifndef __SLIST_H__
#define __SLIST_H__
#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

Node* reverse(Node* head)
{
	// Can we use less than 3 pointers?
	Node* prev = NULL;
	while (head != NULL)
	{
		Node* next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return prev;
}

Node* reverseRecursive(Node* head)
{
	// Can we use tail recursion?
	if (head->next == NULL)
		return head;
	Node* next = head->next;
	Node* new_head = reverse(next);
	next->next = head;
	head->next = NULL;
	return new_head;
}

Node* reverseTailRecursive(Node* head, Node* prev)
{
	if (head->next == NULL)
	{
		head->next = prev;
		return head;
	}
	Node* next = head->next;
	head->next = prev;
	return reverseTailRecursive(next, head);
}

void testReverse()
{
	Node n4 = {4, NULL};
	Node n3 = {3, &n4};
	Node n2 = {2, &n3};
	Node n1 = {1, &n2};
	Node* head = reverseTailRecursive(&n1, NULL);
	while (head != NULL)
	{
		std::cout << head->data << std::endl;
		head = head->next;
	}
}

#endif