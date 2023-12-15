#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int ItemType;

typedef struct node
{
	ItemType member;
	struct node* left;
	struct node* right;
} Node;

/*stack*/
typedef struct stack
{
    int size;
    Node* array[0x1000];
} Stack;

static Stack stack = {0};
int StackIsEmpty()
{
    return stack.size == 0;
}

Node * StackPop()
{
    if (stack.size != 0)
    {
        return stack.array[stack.size--];
    }
    else
    {
        return NULL;
    }
}

int StackPush(Node * node)
{
    stack.array[++(stack.size)] = node;
    return 1;
}



// private funtion
static Node* TreeNewNode(int menber)
{
	Node* node = malloc(sizeof(Node));
	node->member = menber;
	node->left = NULL;
	node->right = NULL;
	return node;
}

static int TreeFreeNode(Node* node)
{
	free(node);
	return 1;
}

// public function
// 先序遍历 中左右
void preOrder(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	printf("%d,", tree->member);
	preOrder(tree->left);
	preOrder(tree->right);
}
// 中序遍历 左中右
void inOrder(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->left);
	printf("%d,", tree->member);
	inOrder(tree->right);
}
// 后序遍历 左右中
void posOrder(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	posOrder(tree->left);
	posOrder(tree->right);
	printf("%d,", tree->member);
}
// 使用栈先序遍历 中左右
void preOrderStack(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}

    StackPush(tree);
    while (!StackIsEmpty())
    {
        tree = StackPop();
        printf("%d,", tree->member);
        if (tree)
        {
            /* code */
        }
        
    }
    

	printf("%d,", tree->member);
	preOrder(tree->left);
	preOrder(tree->right);
}
// 使用栈中序遍历 左中右
void inOrderStack(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	inOrder(tree->left);
	printf("%d,", tree->member);
	inOrder(tree->right);
}
// 使用栈后序遍历 左右中
void posOrderStack(Node* tree)
{
	if (tree == NULL)
	{
		return;
	}
	posOrder(tree->left);
	posOrder(tree->right);
	printf("%d,", tree->member);
}

void test_inOrder()
{
	Node* tree = TreeNewNode(1);
	tree->left = TreeNewNode(2);
	tree->right = TreeNewNode(3);
	tree->left->left = TreeNewNode(4);
	tree->left->right = TreeNewNode(5);
	tree->right->left = TreeNewNode(6);
	tree->right->right = TreeNewNode(7);
	preOrder(tree);
	printf("\n");
	preOrderStack(tree);
	printf("\n");
	inOrder(tree);
	printf("\n");
	inOrderStack(tree);
	printf("\n");
	posOrder(tree);
	printf("\n");
	posOrderStack(tree);
	printf("\n");
}

// main function
int main(int argc, char const* argv[])
{
	test_inOrder();
	return 0;
}
