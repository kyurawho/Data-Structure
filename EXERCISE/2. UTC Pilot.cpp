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
	char name[100];
	int fuel;
	bool status;
	struct Node* next;
	struct Node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(char name[], int fuel, bool status){
	Node* node = (Node*) malloc(sizeof(Node));
	
	strcpy(node->name, name);
	node->fuel = fuel;
	node->status = status;
	
	node->next = node->prev = NULL;
	
	return node;
}

void pushHead(char name[], int fuel, bool status){
	Node* node = createNode(name, fuel, status);
	
	if(head == NULL){
		head = tail = node;
	}else{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushTail(char name[], int fuel, bool status){
	Node* node = createNode(name, fuel, status);
	
	if(tail == NULL){
		head = tail = node;
	}else{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}

void enqueue(char name[], int fuel, bool status){
	if(head == NULL ||
		(fuel <= head->fuel && head->status == true && status == true) ||
		(fuel <= head->fuel && head->status == false && status == false) ||
		(head->status == false && status == true)){
		pushHead(name, fuel, status);
	}else if(tail == NULL ||
		(fuel >= tail->fuel && tail->status == false && status == false) ||
		(fuel >= tail->fuel && tail->status == true && status == true) ||
		(tail->status == true && status == false)){
		pushTail(name, fuel, status);
	}else{
		if(status){
			curr = head;
			while(curr->next && curr->next->status == true && curr->fuel < fuel){
				curr = curr->next;
			}
			
			Node* node = createNode(name, fuel, status);
			node->next = curr->next;
			curr->next->prev = node;
			
			curr->next = node;
			node->prev = curr;
			
		}else{
			curr = head;
			while(curr->next && curr->next->status == true){
				curr = curr->next;
			}
			
			while(curr->next && curr->next->status == false && curr->fuel < fuel){
				curr = curr->next;
			}
			
			Node* node = createNode(name, fuel, status);
			node->next = curr->next;
			curr->next->prev = node;
			
			curr->next = node;
			node->prev = curr;
		}
	}
}

void dequeue(){
	if(tail == NULL){
		puts("Empty list");
		return;
	}
	
	if(head == tail){
		free(head);
		head = tail = NULL;
		return;
	}
	
	Node* temp = head;
	head = head->next;
	free(temp);
	head->prev = NULL;
}

void display(){
	curr = head;
	int cnt = 0;
	while(curr){
		printf("%s->", curr->name);
		curr = curr->next;
		
		cnt++;
	}
	printf("\nTotal queue: %d\n", cnt);
}

int main(){
	enqueue("FALCON23", 80, false);
	enqueue("EAGLE", 70, false);
	enqueue("OWL", 90, false);
	enqueue("BLACKBIRD", 22, false);
	enqueue("FALCON01", 20, true);
	enqueue("KINGFISHER", 30, true);
	enqueue("RAVEN", 35, true);
	enqueue("HOATZIN", 10, false);
	
	display();
	
	printf("After First Dequeue : \n");
	dequeue();
	dequeue();
	display();
	
	printf("After Second Dequeue : \n");
	dequeue();
	dequeue();
	display();
}
