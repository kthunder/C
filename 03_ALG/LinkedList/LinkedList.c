#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"


// private funtion
static Node* ListNewNode(int menber)
{
	Node* node = malloc(sizeof(Node));
	node->member = menber;
	node->next = NULL;
	return node;
}

static int ListFreeNode(Node* node)
{
	free(node);
	return 1;
}

// public function
int ListIsEmpty(Node* list)
{
	return list == NULL;
}

int ListAppend(Node* list, int member)
{
	assert(list != NULL);
	Node* cur = list;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = ListNewNode(member);
	return 1;
}

int ListRemove(Node* list, int member)
{
	assert(list != NULL);
	Node* cur = list->next;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	ListFreeNode(cur->next);
	cur->next = NULL;
	return 1;
}

int ListDesplay(Node* list)
{
	assert(list != NULL);
	Node* cur = list;
	while (cur->next != NULL)
	{
		printf("%d->", cur->member);
		cur = cur->next;
	}
	printf("%d\n", cur->member);
	return 1;
}

// 合并两个有序链表，升序
Node* mergeLinkedList(Node* list1, Node* list2)
{
	if (list1 == NULL || list2 == NULL)
	{
		return list1 == NULL ? list2 : list1;
	}

	Node* head = list1->member <= list2->member ? list1 : list2;
	Node* cur1 = head->next;
	Node* cur2 = head == list1 ? list2 : list1;
	Node* pre = head;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->member <= cur2->member)
		{
			pre->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			pre->next = cur2;
			cur2 = cur2->next;
		}
		pre = pre->next;
	}

	pre->next = cur1 == NULL ? cur2 : cur1;
	return head;
}

int main(int argc, char const* argv[])
{
	Node* list1 = ListNewNode(1);
	ListAppend(list1, 3);
	ListAppend(list1, 5);
	ListAppend(list1, 7);
	ListAppend(list1, 9);
	ListDesplay(list1);

	Node* list2 = ListNewNode(2);
	ListAppend(list2, 4);
	ListAppend(list2, 6);
	ListAppend(list2, 8);
	ListAppend(list2, 10);
	ListDesplay(list2);

	Node* list3 = mergeLinkedList(list1, list2);
	ListDesplay(list3);
	return 0;
}
