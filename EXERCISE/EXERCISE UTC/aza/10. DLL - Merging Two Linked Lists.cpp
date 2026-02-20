#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
typedef long long ll;

int n, T, N, M;

#define Repp(i, l, r, a) for (int i = l; i < r; i += a)
#define Rep(i, l, r) Repp(i, l, r, 1)
#define For(i, n) Rep(i, 0, n)
#define Fori(i, n) Rep(i, 1, n + 1)
#define min(A,B) (A < B ? A:B)
#define max(A,B) (A > B ? A:B)

typedef struct Node{
	int val;
	struct Node* next;
	struct Node* prev;
}Node;

Node* head[2] = {NULL, NULL};
Node* curr = NULL;
Node* tail[2] = {NULL, NULL};

Node* createNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->val = val;
	node->next = node->prev = NULL;
	
	return node;
}

void push(int val, int idx){
	Node* node = createNode(val);
	
	if(head[idx] == NULL){
		head[idx] = tail[idx] = node;
	}else{
		tail[idx]->next = node;
		node->prev = tail[idx];
		tail[idx] = node;
	}
}

void display(){
	tail[0]->next = head[1];
	head[1]->prev = tail[0];
	
	head[1] = tail[1] = NULL;
	
	curr = head[0];
	while(curr){
		printf("%d ", curr->val);
		curr = curr->next;
	}
}

int main(){
	scanf("%d %d", &N, &M);
	
	while(N--){
		scanf("%d", &n);
		push(n, 0);
	}
	
	while(M--){
		scanf("%d", &n);
		push(n, 1);
	}
	
	display();
}
