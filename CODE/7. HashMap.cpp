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

const int size = 10;

typedef struct Node{
	char name[30];
	struct Node* next; // SLL Implementation
}Node;

Node* head[size];
Node* curr = NULL;

Node* createNode(char name[]){
	Node* node = (Node*)malloc(sizeof(Node));
	
	strcpy(node->name, name);
	node->next = NULL;
	
	return node;
}

int hash(char name[]){ // Depends on what requested (can be flexible)
	int total = 0;
	
	For(i, strlen(name)){
		total += name[i];
	}
	
	return total % size;
}

void push(char name[]){
	Node* node = createNode(name);
	
	int key = hash(name);
	
	if(head[key] == NULL){
		head[key] = node;
	}else{
		curr = head[key];
		while(curr->next){ // pushTail without tail itself
			curr = curr->next;
		}
		curr->next = node;
	}
}

void pop(char name[]){
	int key = hash(name);
	
	if(head[key] == NULL){ // The table is empty
		printf("No data available!\n");
		return;
	}
	
	if(strcmp(head[key]->name, name) == 0){ // If it's on head of the table
		Node* temp = head[key];
		head[key] = head[key]->next; // Assign new head to the head->next
		free(temp);
		return;
	}
	
	curr = head[key];
	while(curr->next && strcmp(curr->next->name, name) != 0){ // Find position BEFORE target 
		curr = curr->next;
	}
	
	if(curr->next == NULL){ // If data is not in the table
		printf("No data available!\n");
		return;
	}
	
	// SLL MIDDLE DELETION
	Node* temp = curr->next;
	curr->next = temp->next;
	free(temp);
}

void print(){
	For(i, size){
		printf("[%d]: ",i);
		curr = head[i];
		while(curr!=NULL){
			printf("%s -> ",curr->name);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main(){
	push("Andi");
	push("Tono");
	push("Budi");
	push("Rika");
	push("Alvin");
	push("Steven");
	push("Cherry");
	push("David");
	push("Billy");
	push("Silvy");
	push("Eko");
	push("Flory");
	push("Endah");
	push("Robby");
	push("Dian");
	push("Michael");
	push("Amber");
	push("Cindy");
	push("Mira");
	push("Nella");
	
	print();
	
	pop("Cindy");
	pop("John");
	
	print();
}
