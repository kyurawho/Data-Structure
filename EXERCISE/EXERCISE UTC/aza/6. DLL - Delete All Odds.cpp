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
Node* curr = NULL;
Node* tail = NULL;

Node* createNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->val = val;
	
	node->next = node->prev = NULL;
	
	return node;
}

void push(int val){
	Node* node = createNode(val);
	
	if(head == NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void popHead(){
	if(head == NULL){
		puts("Empty list");
		return;
	}
	
	Node* temp = head;
	if(head == tail){
		head = tail = NULL;
	}else{
		head = head->next;
		head->prev = NULL;
	}
	free(temp);
}

void popTail(){
	if(tail == NULL){
		puts("Empty list");
		return;
	}
	
	Node* temp = tail;
	if(head == tail){
		head = tail = NULL;
	}else{
		tail = tail->prev;
		tail->next = NULL;
	}
	free(temp);
}

void popMid(int val){
	if(head == NULL){
		puts("Empty list");
		return;
	}
	
	if(val == head->val){
		popHead();
		return;
	}
	
	if(val == tail->val){
		popTail();
		return;
	}
	
	curr = head;
	while(curr && val != curr->val){
		curr = curr->next;
	}
	
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	
	free(curr);
}

void display(){
	curr = tail;
	int i = 0;
	while(curr){
		Node* temp = curr->prev;
		
		if(curr->val % 2){
			popMid(curr->val);
		}
		
		curr = temp;
	}
	
	if(tail->val % 2) popTail();
	
	curr = tail;
	
	if(tail == NULL){
		puts("-1");
		return;
	}
	while(curr){
		printf("%d ", curr->val);
		curr = curr->prev;
	}
}

void cek(){
	curr = tail;
	while(curr){
		printf("%d -> ", curr->val);
		curr = curr->prev;
	}
	printf("NULL\n");
}

int main(){
	scanf("%d", &T);
	For(i, T){
		scanf("%d", &n);
		push(n);
	}
	
	cek();
	display();
}
