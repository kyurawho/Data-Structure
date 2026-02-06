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
	int priority;
	char *name;
	struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(int priority, char *name){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->name = (char*)malloc(strlen(name) + 1);
	strcpy(node->name, name);
	node->priority = priority;
	node->next = NULL;
	
	return node;
}

void push(int priority, char* name){
	Node* node = createNode(priority, name);
	
	if(head == NULL){
		head = tail = node;
	}else if(priority <= head->priority){
		node->next = head;
		head = node;
	}else{
		curr = head;
		while(curr->next && curr->next->priority <= priority){
			curr = curr->next;
		}
		
		node->next = curr->next;
		curr->next = node;
	}
}

void display(){
  puts("Current SLL: ");
  curr = head;
  
  while(curr){
    printf("%s | %d -> ", curr->name, curr->priority);
    curr = curr->next;
  }
  
  printf("NULL\n");
}

int main(){
	char name[100], prio[100];
	int age;
	For(i, 5){
		scanf(" %s", name);
		scanf(" %d", &age);
		scanf(" %s", prio);
		
		if(!strcmp(prio, "low")) push(3, name);
		else if(!strcmp(prio, "mid")) push(2, name);
		else if(!strcmp(prio, "high")) push(1, name);
	}
	
	display();
}
