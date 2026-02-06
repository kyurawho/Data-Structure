#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
typedef long long ll;

int n, T;

#define Repp(i, l, r, a) for (int i = l; i < r; i += a)
#define Rep(i, l, r) Repp(i, l, r, 1)
#define For(i, n) Rep(i, 0, n)
#define Fori(i, n) Rep(i, 1, n + 1)
#define min(A,B) (A < B ? A:B)
#define max(A,B) (A > B ? A:B)

struct Node{
	int val;
	struct Node *next;
} *head = NULL, *curr = NULL;

void insert(int x){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	
	node->val = x;
	node->next = head;
	head = node;
}

void display(){
	printf ("Current Linked List:\n\n");
	curr = head;
	
	while (curr){
		printf ("%d -> ", curr->val);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

void search(int x){
	int counter;
	curr = head;
	
	while (curr){
		counter++;
		if(curr->val == x) printf("%d\n", counter);
		curr = curr->next;
	}
}

int main(){
	struct Node *node1 = (struct Node*) malloc(sizeof(struct Node));
	struct Node *node2 = (struct Node*) malloc(sizeof(struct Node));
	struct Node *node3 = (struct Node*) malloc(sizeof(struct Node));
	
	node1->val = 10;
	node1->next = node2;
	node2->val = 100;
	node2->next = node3;
	node3->val = 1000;
	node3->next = NULL;
	
//	printf("node1 : %d\n", node1->val);
//	printf("node2 : %d\n", node1->next->val);
//	printf("node3 : %d\n", node3->val);
	insert(50);
	insert(40);
	insert(30);
	insert(20);
	insert(10);
	
	display();
	search(40);
	
	free(node1);
	free(node2);
	free(node3);
}
