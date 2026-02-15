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
	int val;
	struct Node* left;
	struct Node* right;
}Node;

Node* root = NULL;

Node* createNode(int val){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->val = val;
	
	node->left = node->right = NULL;
	
	return node;
}

Node* push(Node* curr, int val){
	if(curr == NULL) curr = createNode(val);
	
	else if(curr->val != val){
		if(val < curr->val) curr->left = push(curr->left, val);
		else curr->right = push(curr->right, val);
	}
	
	return curr;
}

int left = 0;
int right = 0;

void inOrderL(Node* curr){
	if(curr->left) inOrderL(curr->left);
	left += curr->val;
	if(curr->right) inOrderL(curr->right);
}

void inOrderR(Node* curr){
	if(curr->left) inOrderR(curr->left);
	right += curr->val;
	if(curr->right) inOrderR(curr->right);
}

int main(){
	scanf("%d", &T);
	
	int temp = T;
	
	while(T--){
		scanf("%d", &n);
		root = push(root, n);
		
		if(T + 1 == temp){
			printf("0\n");
			continue;
		}
		
		left = right = 0;
		if(root->left) inOrderL(root->left);
		if(root->right) inOrderR(root->right);
		
		printf("%d\n", abs(left - right));
	}
}
