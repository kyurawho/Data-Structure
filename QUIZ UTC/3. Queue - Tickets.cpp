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
	int id;
	int tickets;
	struct Node* next;
}Node;

Node* head = NULL;
Node* heads = NULL;
Node* curr = NULL;
Node* tail = NULL;

Node* createNode(int id, int tickets){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->id = id;
	node->tickets = tickets;
	
	node->next = NULL;
	
	return node;
}

void pushs(int id, int tickets){
	Node* node = createNode(id, tickets);
	
	if(heads == NULL){
		heads = node;
	}else{
		node->next = heads;
		heads = node;
	}
}

void push(int id, int tickets){
	Node* node = createNode(id, tickets);
	
	if(head == NULL){
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}

void display(){
	curr = head;
	bool flag = true;
	while(curr){
		T -= curr->tickets;
		if(T < 0){
			flag = false;
			printf("%d ", curr->id);
		}else if(curr->tickets > 5){
			pushs(curr->id, curr->tickets);
		}
		
		curr = curr->next;
	}
	
	if(flag) printf("None");
	printf("\n");
}

void displays(){
	curr = heads;
	if(heads == NULL){
		printf("0\n");
		return;
	}
	while(curr){
		printf("%d ", curr->id);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	int p;
	scanf("%d %d", &T, &p);
	while(p--){
		int t;
		scanf("%d %d", &n, &t);
		push(n, t);
	}
	
	display();
	displays();
}
