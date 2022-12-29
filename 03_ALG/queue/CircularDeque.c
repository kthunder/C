/*
	leetcode 641
	//1 <= k <= 1000
	//0 <= value <= 1000
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int head;
	int tail;
	int capacity;
	int length;
	int* array;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k)
{
	int* array = malloc(sizeof(int) * k);
	MyCircularDeque* obj = malloc(sizeof(MyCircularDeque));
	if (!array || !obj)
		return NULL;

	obj->head = 0;
	obj->tail = 0;
	obj->capacity = k;
	obj->length = 0;
	obj->array = array;
	return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value)
{
	if (obj->length == obj->capacity)
	{
		return false;
	}

	if (obj->length == 0)
	{
		obj->array[obj->head] = value;
		obj->length++;
	}
	else
	{
		obj->head = (obj->head + obj->capacity - 1) % obj->capacity;
		obj->array[obj->head] = value;
		obj->length++;
	}

	return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value)
{
	if (obj->length == obj->capacity)
	{
		return false;
	}

	if (obj->length == 0)
	{
		obj->array[obj->tail] = value;
		obj->length++;
	}
	else
	{
		obj->tail = (obj->tail + 1) % obj->capacity;
		obj->array[obj->tail] = value;
		obj->length++;
	}

	return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj)
{
	if (obj->length == 0)
	{
		return false;
	}

	if (obj->length == 1)
	{
		obj->length--;
	}
	else
	{
		obj->head = (obj->head + 1) % obj->capacity;
		obj->length--;
	}

	return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj)
{
	if (obj->length == 0)
	{
		return false;
	}

	if (obj->length == 1)
	{
		obj->length--;
	}
	else
	{
		obj->tail = (obj->tail + obj->capacity - 1) % obj->capacity;
		obj->length--;
	}

	return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj)
{
	if (obj->length == 0)
	{
		return -1;
	}

	return obj->array[obj->head];
}

int myCircularDequeGetRear(MyCircularDeque* obj)
{
	if (obj->length == 0)
	{
		return -1;
	}

	return obj->array[obj->tail];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj)
{
	return obj->length == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj)
{
	return obj->length == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj)
{
	if (obj)
	{
		free(obj->array);
		free(obj);
	}
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/