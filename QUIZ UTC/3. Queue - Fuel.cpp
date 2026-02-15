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
	int fuel;
	struct Node* next;
}Node;

Node* head = NULL;
Node* curr = NULL;
Node* tail = NULL;

Node* createNode(int id, int fuel){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->id = id;
	node->fuel = fuel;
	
	node->next = NULL;
	
	return node;
}

void push(int id, int fuel){
	Node* node = createNode(id, fuel);
	
	if(head == NULL){
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}

void display(int fuel){
	curr = head;
	printf("Success IDs: ");
	
	while(curr){
		if(fuel - curr->fuel >= 0){
			fuel -= curr->fuel;
			printf("%d ", curr->id);
		}
		curr = curr->next;
	}
}

int main(){
	scanf("%d %d", &T, &n);
	while(T--){
		int id, f;
		scanf("%d %d", &id, &f);
		push(id, f);
	}
	display(n);
}
