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
	int level;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int value, int level){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->value = value;
	node->level = level;
	
	node->right = node->left = NULL;
	
	return node;
}

Tree* push(Tree* curr, int value, int level){
	if(curr == NULL) curr = createNode(value, level);
	else if(value != curr->value){
		if(value < curr->value) curr->left = push(curr->left, value, level + 1);
		else curr->right = push(curr->right, value, level + 1);
	}
	
	return curr;
}

int getHeight(Tree* curr){
	if(curr == NULL) return -1;
	
	int left = getHeight(curr->left);
	int right = getHeight(curr->right);
	
	return max(left, right) + 1;
}

Tree* findMin(Tree* curr){
	if(curr == NULL) return NULL;
	if(curr->left == NULL) return curr;
	return findMin(curr->left);
}

Tree* findMax(Tree* curr){
	if(curr == NULL) return NULL;
	if(curr->right == NULL) return curr;
	return findMax(curr->right);
}

void display(Tree* curr, int level){
	if(curr->left) display(curr->left, level);
	if(curr->level == level) printf("%d ", curr->value);
	if(curr->right) display(curr->right, level);
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		root = push(root, n, 0);
	}
	
	
	printf("%d\n", findMin(root)->value);
	printf("%d\n", findMax(root)->value);
	display(root, getHeight(root));
}
