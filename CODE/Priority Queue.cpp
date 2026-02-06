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

typedef struct Node {
	int data;
	int priority;
	struct Node* next;
}Node;

Node* head = NULL;
Node* curr = NULL;

void push(int data, int priority){
	Node* node = (Node*) malloc (sizeof(Node));
	
	node->data = data;
	node->priority = priority;
	node->next = NULL;
	
	if(head == NULL || priority < head->priority){
		node->next = head;
		head = node;
		return;
	}
	
	curr = head;
	while(curr->next != NULL && curr->next->priority <= priority){
		curr = curr->next;
	} 
	
	node->next = curr->next;
	curr->next = node;
}

int main(){

}
