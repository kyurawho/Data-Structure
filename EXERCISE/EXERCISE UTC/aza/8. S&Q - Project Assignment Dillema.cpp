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

int size = 0;

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* heads = NULL;
Node* tails = NULL;

Node* createNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->val = val;
	node->next = NULL;
	
	return node;
}

void push(int val){
	Node* node = createNode(val);
	
	if(head == NULL){
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}

void pushs(int val){
	Node* node = createNode(val);
	
	if(heads == NULL) heads = tails = node;
	else{
		tails->next = node;
		tails = node;
	}
}

void popHead(){
	if(head == NULL){
		puts("Empty list");
		return;
	}
	
	Node* temp = head;
	head = head->next;
	
	if(head == NULL) tail = NULL;
	free(temp);
}

void popHeads(){
	if(heads == NULL){
		puts("Empty list");
		return;
	}
	
	Node* temp = heads;
	heads = heads->next;
	
	free(temp);
}

void display(){
	int cnt = 0;
	
	while(head && heads){
		if(head->val == heads->val){
			popHead();
			popHeads();
			size--;
			cnt = 0;
		}else{
			int val = head->val;
			popHead();
			push(val);
			cnt++;
		}
		if(cnt == size) break;
	}
	
	printf("%d\n", size);
}

int main(){
	scanf("%d", &T);
	
	size = T;
	
	For(i, T){
		scanf("%d", &n);
		push(n);
	}
	
	For(i, T){
		scanf("%d", &n);
		pushs(n);
	}
	
	display();
}
