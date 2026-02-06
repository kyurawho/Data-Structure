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

typedef struct Tree{
	int value;
	char name[35];
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int value, char name[]){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->value = value;
	strcpy(node->name, name);
	
	node->left = node->right = NULL;
	
	return node;
}

void inOrder(Tree* curr){
	if(curr->left) inOrder(curr->left);
	printf("BN%04d - %s\n", curr->value, curr->name);
	if(curr->right) inOrder(curr->right);
}

Tree* push(Tree* curr, int value, char name[]){
	if(curr == NULL){
		curr = createNode(value, name);
	}
	
	else if(curr->value != value){
		if(value < curr->value){
			curr->left = push(curr->left, value, name);
		}else{
			curr->right = push(curr->right, value, name);
		}
	}
	
	return curr;
}

int main(){
	scanf("%d", &T);
	while(T--){
		char s[30];
		scanf("%d %[^\n]", &n, s);
		root = push(root, n, s);
	}
	
	inOrder(root);
}
