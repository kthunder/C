typedef int ListItem;
typedef struct node * List;

typedef struct node
{
	int member;
	struct node* next;
} Node;

List ListInit(int size);					// 表结构初始化
int ListEmpty(List L);						// 测试表L是否为空
int ListLength(List L);						// 表L的长度
ListItem ListRetrieve(int k, List L);		// 返回表L的位置k处的元素
int ListLocate(ListItem x, List L);			// 元素x在表L中的位置
void listinsert(int k, ListItem x, List L); // 在表L的位置k之后插入元素x
ListItem ListDelete(int k, List L);			// 从表L中删除位置k处的元素
void Printlist(List L);						// 按位置次序输出表L中元素
