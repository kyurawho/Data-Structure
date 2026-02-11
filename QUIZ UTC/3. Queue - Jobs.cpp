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
	int ink;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head = NULL;
Node* curr = NULL;
Node* tail = NULL;

int total = 0;

Node* createNode(int id, int ink){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->id = id;
	node->ink = ink;
	total += ink;
	node->prev = node->next = NULL;
	
	return node;
}

void push(int id, int ink){
	Node* node = createNode(id, ink);
	
	if(head == NULL) head = tail = node;
	else{
		head->next = node;
		node->prev = head;
		head = node;
	}
}

void display(int ink){
	curr = tail;
	int temp = 0;
	while(curr){
		temp += curr->ink;
		if(temp > ink) printf("%d ", curr->id);
		curr = curr->next;
	}
}

int main(){
	scanf("%d %d", &T, &n);
	while(T--){
		int id, ink;
		scanf("%d %d", &id, &ink);
		push(id, ink);
	}
	
	
	if(total > n){
		display(n);
	}else{
		puts("Completed");
	}
}
