#include <stdio.h>
#include <stdlib.h>

// LNode单链表节点 *LinkList单链表(不带头结点)
typedef struct LNode {
	int val;
	struct LNode *next; 
}LNode, *LinkList;

// create 依据控制台输入,创建单链表
// @return {LinkList} 创建的单链表
LinkList create() {
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;

	printf("请输入待逆数据数量,至少三个:");
	int n;
	scanf("%d",&n);
	
	printf("请输入待逆数据:");
	LNode *prev = head;
	for(int i = 0;i < n;i++) {
		if(i == 0) {
			scanf("%d",&head->val);			
		} else {
			LNode *node = (LNode *)malloc(sizeof(LNode));
			scanf("%d",&node->val);
			node->next = NULL;
			prev->next = node;
			prev = node;
		}
	}

	return head;
}

// destroy 销毁单链表
// @param list {LinkList} 要销毁的单链表
void destroy(LinkList list) {
	if(list == NULL) {
		return;
	}
	
	destroy(list->next);
	free(list);
}

// reverse 原地反转单链表
// @param list {LinkList} 单链表
// @return {LinkList} 反转后的单链表第一个节点
LinkList reverse(LinkList list) {
	if(list == NULL || list->next == NULL) {
		return list;
	}
	
	LinkList newListHead = reverse(list->next);
	list->next->next = list;
	list->next = NULL;
	return newListHead;
}

// printList 输出单链表
// @param list {LinkList}
void printList(LinkList list) {
	if(list == NULL) {
		printf("\n");
		return;
	}
	printf("%d ",list->val);
	printList(list->next);
}

int main() {
	LinkList list = create();
	
	printf("输入数据: ");
	printList(list);
	
	list = reverse(list);
	printf("反转后数据: ");
	printList(list);
	
	destroy(list);
	return 0;
}
