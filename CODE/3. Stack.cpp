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
	int value;
	struct Node* next;
}Node;

Node* head = NULL;

//make a new node and set the value
Node* createNode(int value){
  Node* node = (Node*) malloc(sizeof(Node));
  
  node->value = value; //set data value
  node->next = NULL; //set pointer to NULL for temporary
  
  return node;
}

void push(int value){
	Node* node = createNode(value);
	
	if(head == NULL){ //if the list is empty
		head = node; //set head and tail to the new node
	}else{
		node->next = head; //set new node pointer to head
		head = node; //set new node as head
	}
}

void pop(){
	if(head == NULL){ //if the list is empty
		puts("List kosong.");
		return;
	}
	
	Node* temp = head; //save the head for temporary
	head = head->next; //set head to the next node;
	
	free(temp); //free the head to avoid memory leaking
}

int peek(){
	if(head == NULL){ //if the list is empty
		puts("List kosong.");
		return NULL;
	}
	
	return head->value;
}

int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	printf("Current top : %d\n", peek());
	pop();
	printf("Current top : %d\n", peek());
	pop();
	printf("Current top : %d\n", peek());
	pop();
	printf("Current top : %d\n", peek());
	pop();
	printf("Current top : %d\n", peek());
}
