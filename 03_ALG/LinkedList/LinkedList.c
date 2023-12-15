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

// 两个链表相加
Node* addLinkedList(Node* list1, Node* list2)
{
	Node* ans = NULL;
	Node* cur = NULL;
	Node* tmp = NULL;
	int sum = 0;
	int carry = 0;

	while (list1 != NULL || list2 != NULL)
	{
		// 节点求和
		sum = (list1 == NULL ? 0 : list1->member) + (list2 == NULL ? 0 : list2->member) + carry;
		carry = sum / 10;
		// 释放内存
		if (list1 != NULL)
		{
			tmp = list1;
			list1 = list1->next;
			ListFreeNode(tmp);
		}

		if (list2 != NULL)
		{
			tmp = list2;
			list2 = list2->next;
			ListFreeNode(tmp);
		}
		// 增长新链表
		if (ans == NULL)
		{
			ans = ListNewNode(sum % 10);
			cur = ans;
		}
		else
		{
			cur->next = ListNewNode(sum % 10);
			cur = cur->next;
		}
	}

	if (carry != 0)
	{
		cur->next = ListNewNode(carry);
	}

	return ans;
}

// 划分链表
Node* partitionLinkedList(Node* list, ListItem x)
{
	if (list == NULL)
		return NULL;

	Node* ans = NULL;
	Node* leftHead = NULL;
	Node* leftTail = NULL;
	Node* rightHead = NULL;
	Node* rightTail = NULL;
	Node* cur = list;
	while (cur != NULL)
	{
		if (cur->member < x)
		{
			if (leftHead == NULL)
			{
				leftHead = cur;
				leftTail = cur;
			}
			else
			{
				leftTail->next = cur;
				leftTail = cur;
			}
		}
		else
		{
			if (rightHead == NULL)
			{
				rightHead = cur;
				rightTail = cur;
			}
			else
			{
				rightTail->next = cur;
				rightTail = cur;
			}
		}
		cur = cur->next;
	}

	if (leftTail != NULL)
	{
		leftTail->next = rightHead;
	}
	if (rightTail != NULL)
	{
		rightTail->next = NULL;
	}

	ans = (leftHead == NULL ? rightHead : leftHead);

	return ans;
}

void test_merge()
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
	ListAppend(list2, 1);
	ListDesplay(list2);

	Node* list3 = mergeLinkedList(list1, list2);
	ListDesplay(list3);
}

void test_add()
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
	ListAppend(list2, 1);
	ListDesplay(list2);

	Node* list3 = addLinkedList(list1, list2);
	ListDesplay(list3);
}

void test_partition()
{
	Node* list = ListNewNode(9);
	ListAppend(list, 3);
	ListAppend(list, 6);
	ListAppend(list, 7);
	ListAppend(list, 5);
	ListAppend(list, 1);
	ListAppend(list, 2);
	ListAppend(list, 3);
	ListDesplay(list);

	Node* res = partitionLinkedList(list, 5);
	ListDesplay(res);
}

int main(int argc, char const* argv[])
{
	// test_merge();
	// test_add();
	test_partition();
	return 0;
}
