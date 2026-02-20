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
	int val;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int val){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->val = val;
	node->left = node->right = NULL;
	
	return node;
}

Tree* push(Tree* curr, int val){
	if(curr == NULL) curr = createNode(val);
	
	else if(val != curr->val){
		if(val < curr->val) curr->left = push(curr->left, val);
		else curr->right = push(curr->right, val);
	}
	
	return curr;
}

Tree* findMax(Tree* curr){
	while(curr->right) curr = curr->right;
	return curr;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		root = push(root, n);
		printf("%d\n", findMax(root)->val);
	}
}
