/*
ASSIGNMENT PPTI 22 BEFORE UTC

Shuttle Schedule
===============
1. Add New Schedule
2. Dispatch a Bus
3. View Schedule
4. Exit
Choose [1..4]:


MENU 1: (push mid based on departure time)
Departure Time [hh:mm]: 09:20
Arrival Time [hh:mm]: 11:20
Source [minimum 3 words]: Alam Sutera
Destination [minimum 3 words]: Sentul
Schedule added!

MENU 2: (pop head)
Bus from Bekasi to Sentul departs at 9.20 and will arrive at 11.20

MENU 3: (Display)
Departure Time	| Arrival Time	| Source		| Destination
09:20			| 11:20			| Alam Sutera	| Sentul
11:20			| 13:20			| Anggrek		| Sentul
16:20			| 18:20			| Sentul		| Anggrek
16:20			| 18:20			| Sentul		| Alam Sutera
*/

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
	int time;
	char dep[10];
	char arr[10];
	char* src;
	char* dest;
	struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(int time, char dep[], char arr[], char src[], char dest[]){
	Node* node = (Node*) malloc (sizeof(Node));
	
	node->src = (char*)malloc(strlen(dest) + 1);
	node->dest = (char*)malloc(strlen(dest) + 1);
	
	node->time = time;
	strcpy(node->dep, dep);
	strcpy(node->arr, arr);
	strcpy(node->src, src);
	strcpy(node->dest, dest);
	
	node->next = NULL;
	
	return node;
}

int timeis(char time[]){
	int hour = 0, minute = 0;
	
	hour = time[0] - '0';
	hour = hour * 10 + (time[1] - '0');
	
	minute = time[3] - '0';
	minute = minute * 10 + (time[4] - '0');
	
	return hour * 60 + minute;
}

void pushHead(int time, char dep[], char arr[], char src[], char dest[]){
	Node* node = createNode(time, dep, arr, src, dest);
	
	if(head == NULL) head = tail = node;
	else{
		node->next = head;
		head = node;
	}
}

void pushTail(int time, char dep[], char arr[], char src[], char dest[]){
	Node* node = createNode(time, dep, arr, src, dest);
	
	if(tail == NULL) head = tail = node;
	else{
		tail->next = node;
		tail = node;
	}
}

void pushMid(int time, char dep[], char arr[], char src[], char dest[]){
	if(head == NULL || time <= head->time) pushHead(time, dep, arr, src, dest);
	else if(time >= tail->time) pushTail(time, dep,arr, src, dest);
	else{
		curr = head;
		
		while(curr->next && time < curr->next->time){
			curr = curr->next;
		}
		
		Node* node = createNode(time, dep, arr, src, dest);
		node->next = curr->next;
		curr->next = node;
	}
}

void popHead(){
	if(head == NULL){
		puts("Empty");
		return;
	}
	
	printf("Bus from %s to %s departs at %s and will arive at %s\n", head->src, head->dest, head->dep, head->arr);
	
	Node* temp = head;
	head = head->next;
	
	if(head == NULL) tail = NULL;
	free(head);
}

void display(){
	curr = head;
	printf("Departure Time	| Arrival Time	| Source		| Destination\n");
	while(curr){
		printf("%s | %s | %s |%s\n", curr->dep, curr->arr, curr->src, curr->dest);
		curr = curr->next;
	}
}

int main(){
	int ch = -1;

	while(ch != 4){
		puts("1. Add New Schedule");
		puts("2. Dispatch a Bus");
		puts("3. View Schedule");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &ch);
		
		int time;
		char dep[1000], arr[1000], src[1000], dest[1000];
		switch(ch){
			case 1:{
				printf("Departure time [hh:mm]: ");
				scanf(" %s", dep);
				printf("Arrival time [hh:mm]: ");
				scanf(" %s", arr);
				printf("Source [minimum 3 words]: ");
				scanf(" %[^\n]", src);
				printf("Destination [minimum 3 words]: ");
				scanf(" %[^\n]", dest);
				
				time = timeis(dep);
				pushMid(time, dep, arr, src, dest);
				puts("Successfully added!");
				break;
			}
			case 2:{
				popHead();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:
				puts("Exiting...");
				break;
			default:
				puts("Invalid format");
				break;
		}
	}
}
