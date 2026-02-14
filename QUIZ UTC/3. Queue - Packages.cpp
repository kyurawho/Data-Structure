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
	int w;
	struct Node* next;
}Node;

Node* heads = NULL;
Node* head = NULL;
Node* curr = NULL;
Node* tail = NULL;

Node* createNode(int id, int w){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->id = id;
	node->w = w;
	
	node->next = NULL;
	
	return node;
}

void pushs(int id, int w){
	Node* node = createNode(id, w);
	
	if(heads == NULL){
		heads = node;
	}else{
		node->next = heads;
		heads = node;
	}
}

void push(int id, int w){
	Node* node = createNode(id, w);
	
	if(head == NULL){
		head = tail = node;
	}else{
		tail->next = node;
		tail = node;
	}
}

int x[1005];

void display(int m, int u){
	curr = head;
	bool flagc = false, flagl = false;
	while(curr){
		flagl = false;
		For(i, u){
			if(curr->id == x[i]){
				flagl = true;
				pushs(curr->id, curr->w);
				continue;
			}
		}
		
		if(flagl){
			curr = curr->next;
			continue;
		}
		
		m -= curr->w;
		if(m < 0){
			flagc = true;
			printf("%d ", curr->id);
		}
		curr = curr->next;
	}
	
	if(!flagc) printf("0");
	printf("\n");
}

void displays(){
	curr = heads;
	if(curr == NULL){
		printf("-\n");
		return;
	}
	
	while(curr){
		printf("%d ", curr->id);
		curr = curr->next;
	}
	
	printf("\n");
}

int main(){
	int t, m, p, w, u, y;
	scanf("%d %d", &t, &m);
	
	while(t--){
		scanf("%d %d", &p, &w);
		push(p, w);
	}
	
	scanf("%d", &u);
	For(i, u){
		scanf("%d", &y);
		x[i] = y;
	}
	
	display(m, u);
	displays();
}
