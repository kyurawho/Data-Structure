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

typedef struct Node{
	int val;
	struct Node* next;
	struct Node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(int val){
	Node* node = (Node*) malloc(sizeof(Node));
	
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

void pushHead(int val){
	Node* node = createNode(val);
	
	if(head == NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void popTail(){
	if(tail == NULL) return;
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	
	Node* temp = tail;
	tail = tail->prev;
	free(temp);
	tail->next = NULL;
}

void displayTail(){
  printf ("Current DLL:\n\n");
  curr = tail;
  
  while (curr){
    printf ("%d -> ", curr->val);
    curr = curr->prev;
  }
  
  printf("NULL\n");
}

int main(){
	pushHead(100);
	pushHead(150);
	pushHead(70);
	pushHead(90);
	pushHead(5);
	pushHead(10);
	pushHead(12);
	pushHead(13);
	pushHead(20);
	pushHead(25);
	
	displayTail();
	
	popTail();
	popTail();
	popTail();
	popTail();
	popTail();
	
	displayTail();
}
