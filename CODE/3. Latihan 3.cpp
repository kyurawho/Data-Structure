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
	char val;
	struct Node* next;
	struct Node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(char val){
	Node* node = (Node*) malloc(sizeof(Node));
	
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

void pushHead(char val){
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
	if(head == NULL) return;
	
	Node* temp = head;
	head = head->next;
	head->prev = NULL;
	
	if(head == NULL) tail = NULL;
	free(temp);
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

bool pop(){
	if(head->val != tail->val) return false;
	else{
		popHead();
		popTail();
	}
	return true;
}

int main(){
	char s[] = "level";
	
	int i = 0;
	while(s[i] != '\0'){
		pushHead(s[i]);
	}
	
	For(i, strlen(s) / 2){
		if(!pop()){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
