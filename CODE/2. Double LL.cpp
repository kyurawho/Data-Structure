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
	struct Node *prev;
} *head = NULL, *curr = NULL, *tail = NULL;

void insertTail(int x){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	
	//membuat node baru dan melakukan update tail
	node->val = x;
	node->next = NULL;
	node->prev = NULL;
	
	if (head == NULL){
        head = tail = node;
    }else{
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

void insertHead(int x){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	
	//membuat node baru dan melakukan update tail
	node->val = x;
	node->next = NULL;
	node->prev = NULL;
	
	if (head == NULL){
        head = tail = node;
    }else{
        node->prev = head;
        head->next = node;
        head = node;
    }
}

void displayTail(){
	printf ("Current Linked List:\n\n");
	curr = tail;
	
	while (curr){
		printf ("%d -> ", curr->val);
		curr = curr->prev;
	}
	
	printf("NULL\n");
}

void displayHead(){
	printf ("Current Linked List:\n\n");
	curr = head;
	
	while (curr){
		printf ("%d -> ", curr->val);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

int main(){
	insertTail(10);
	insertTail(20);
	insertTail(30);
	insertHead(40);
	insertHead(50);
	insertHead(60);
	displayTail();
	displayHead();
}
