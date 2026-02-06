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

void displayHead(){
  puts("Current DLL: \n\n");
  curr = head;
  
  while(curr){
    printf(" %c -> ", curr->val);
    curr = curr->next;
  }
  
  printf("NULL\n");
}

void displayTail(){
  printf ("Current DLL:\n\n");
  curr = tail;
  
  while (curr){
    printf ("%c -> ", curr->val);
    curr = curr->prev;
  }
  
  printf("NULL\n");
}

int main(){
	char s[] = "Hello";
	
	int cnt = 0;
	while(s[cnt] != '\0'){
		pushHead(s[cnt++]);
	}
	
	displayTail();
	displayHead();
	
	
}
