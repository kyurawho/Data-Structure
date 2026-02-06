#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
typedef long long ll;

typedef struct Node{
	char name[50]; //data
	int age; //data
	struct Node* next; //point to the next node
} Node;

Node* head = NULL; //first node
Node* tail = NULL; //last node
Node* curr = NULL; //current node

//make a new node and set the value
Node* createNode(char name[], int age){
	Node* node = (Node*) malloc(sizeof(Node));
	
	strcpy(node->name, name); //set data value
	node->age = age; //set data value
	node->next = NULL; //set pointer to NULL for temporary
	
	return node;
}

void pushHead(char name[], int age){
	Node* node = createNode(name, age);
	
	if(head == NULL){ //if the list is empty
		head = tail = node; //set head and tail to the new node
	}
	else{
		node->next = head; //set new node pointer to head
		head = node; //set ndw node as head
	}
}

void pushTail(char name[], int age){
	Node* node = createNode(name, age);
	
	if(head == NULL){ //if the list is empty
		head = tail = node; //set head and tail to the new node
	}
	else{
		tail->next = node; //set tail pointer to new node
		tail = node; //set new node as tail
	}
}

void pushMid(char name[], int age){
	if(head == NULL || strcmp(name, head->name) <= 0){ //smaller than equal
		//if the list is empty or new node must be a head
		pushHead(name, age);
	}else if(strcmp(name, tail->name) >= 0){ //grater than equal
		//if new node must be a tail
		pushTail(name, age);
	}else{
		curr = head;
		
		while(curr->next && strcmp(name, curr->next->name) > 0){
			//find the best position for the new node
			curr = curr->next;
		}
		
		Node* node = createNode(name, age); //new node
		node->next = curr->next; //link new node to the next node
		curr->next = node; //update the current node to the new node
	}
}

void popHead(){
	if(head == NULL){ //if the list is empty
		puts("List kosong.");
		return;
	}
	
	Node* temp = head; //save the head for temporary
	head = head->next; //set head to the next node;
	
	if(head == NULL) tail = NULL; //if the list become empty, set tail to NULL
	free(temp); //free the head to avoid memory leaking
}

void popTail(){
	if(tail == NULL){ //if the list is empty
		puts("List kosong.");
		return;
	}
	
	if(head == tail){ //if there is only 1 node
		free(head); //free the head to avoid memory leaking
		head = tail = NULL; //set head and tail to NULL
		return;
	}
	
	curr = head;
	while(curr->next != tail){ //find second last node
		curr = curr->next;
	}
	free(tail); //free the tail to avoid memory leaking
	tail = curr; //update the tail to current (second last node)
	tail->next = NULL; //update the pointer to NULL (cus this is tail);
}

void popMid(char name[]){
	if(head == NULL){ //if the list is empty
		puts("List kosong.");
		return;
	}
	
	if(strcmp(head->name, name) == 0){ //the mid is head
		popHead();
		return;
	}
	
	if(strcmp(tail->name, name) == 0){ //the mid is tail
		popTail();
		return;
	}
	
	curr = head;
	while(curr != NULL && strcmp(curr->next->name, name) != 0){
		//find node before the target node
		curr = curr->next;
	}
	
	if(curr == NULL){ //if not found (already checking all nodes)
		puts("Not found!");
		return;
	}
	
	Node* temp = curr->next; //save the target for temporary
	curr->next = temp->next; // update the pointer (A.next = C)
	
	/*
	curr  ->  target  ->  after
 	A         B          C
	*/
	
	if(!curr->next) tail = curr; // if the pointer is point to NULL, then update the tail
	free(temp); //free the target to avoid memory leaking
}
	

void display(){
	puts("Current SLL: ");
	curr = head;
	
	while(curr){
		printf("%s | %d -> ", curr->name, curr->age);
		curr = curr->next;
	}
	
	printf("NULL\n");
}

int main(){
	pushHead("jeremy", 10);
	pushHead("christopher", 20);
	pushTail("amadeus", 30);
	pushTail("widyanto", 40);
	pushMid("jcaw", 50);
	popHead();
	popTail();
	popMid("jcaw");
	display();
}
