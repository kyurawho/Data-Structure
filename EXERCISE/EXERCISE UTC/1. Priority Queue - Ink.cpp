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
	int p;
	struct Node* next;
}Node;

Node* head = NULL;
Node* curr = NULL;
Node* tail = NULL;

Node* createNode(int id, int ink, int p){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->id = id;
	node->ink = ink;
	node->p = p;
	
	node->next = NULL;
	
	return node;
}

void push(int id, int ink, int p){
	Node* node = createNode(id, ink, p);
	
	
	if(head == NULL){
		head = tail = node;
	}else{
		curr = head;
		
		if(curr->next == NULL){
			if(p < curr->p){
				node->next = head;
				head = node;
			}
			else{
				tail->next = node;
				tail = node;
			}
			return;
		}
		
		while(curr->next && curr->next->p < p){
			curr = curr->next;
		}
		
		if(curr == head){
			node->next = head;
			head = node;
			return;
		}else if(curr == tail){
			tail->next = node;
			tail = node;
			return;
		}
		
		node->next = curr->next;
		curr->next = node;
	}
}

void display(int n){
	curr = head;
	
	bool flag = false;
	
	while(curr){
		
		if(n - curr->ink < 0){
			printf("%d ", curr->id);
			flag = true;
		}
		
		n -= curr->ink;
		
		curr = curr->next;
	}
	
	if(!flag){
		printf("Completed");
	}
	
	puts("");
}

void test(){
	curr = head;
	while(curr){
		printf("%d %d ->", curr->ink, curr->p);
		curr = curr->next;
	}
	printf("NULL\n");
}

int main(){
	scanf("%d %d", &T, &n);
	while(T--){
		int id, ink, p;
		scanf("%d %d %d", &id, &ink, &p);
		push(id, ink, p);
	}
	
//	test();
	display(n);
}
