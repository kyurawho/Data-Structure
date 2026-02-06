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
	struct Node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;

//make a new node and set the value
Node* createNode(int value){
  Node* node = (Node*) malloc(sizeof(Node));
  
  node->value = value;
  node->next = NULL; //set pointer to NULL for temporary
  node->prev = NULL; //set pointer to NULL for temporary
  
  return node;
}

void enqueue(int value){ //pushHead
  Node* node = createNode(value);
  
  if(head == NULL){ //if the list is empty
    head = tail = node; //set head and tail to the new node
  }
  else{
    //head and node pointing each other
    node->next = head; //set new node pointer to head
    head->prev = node; //set head pointer to new node 
    head = node; //set new node as head
  }
}

void dequeue(){ //popTail
  if(tail == NULL){ //if the list is empty
    puts("List kosong.");
    return;
  }
  
  if(head == tail){ //if there is only 1 node
    free(head); //free the head to avoid memory leaking
    head = tail = NULL; //set head and tail to NULL
    return;
  }
  
  Node* temp = tail;
  tail = tail->prev;
  free(temp); //free the tail to avoid memory leaking
  tail->next = NULL; //update the pointer to NULL (cus this is tail AND ALWAYS POINT TO NULL);
}


int peek(){
	if(head == NULL){
		puts("Queue kosong");
		return -1;
	}
	
	return tail->value;
}

int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	printf("Current front : %d\n", peek());
	dequeue();
	printf("Current front : %d\n", peek());
	dequeue();
	printf("Current front : %d\n", peek());
	dequeue();
	printf("Current front : %d\n", peek());
	dequeue();
	printf("Current front : %d\n", peek());
}
