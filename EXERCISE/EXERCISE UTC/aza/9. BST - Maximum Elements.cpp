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
	int cnt;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int val){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->val = val;
	node->left = node->right = NULL;
	node->cnt = 1;
	
	return node;
}

Tree* push(Tree* curr, int val){
	if(curr == NULL) curr = createNode(val);
	else if(curr->val == val) curr->cnt++;
	else if(val < curr->val) curr->left = push(curr->left, val);
	else if(val > curr->val) curr->right = push(curr->right, val);
	return curr;
}

Tree* findMax(Tree* curr){
	while(curr->right) curr = curr->right;
	return curr;
}

Tree* pop(Tree* curr, int val){
	if(curr == NULL){
		return NULL;
	}
	
	else if(val < curr->val) curr->left = pop(curr->left, val);
	else if(val > curr->val) curr->right = pop(curr->right, val);
	
	else if(val == curr->val && curr->cnt > 1){
		curr->cnt--;
	}
	
	else{
		if(curr->right == NULL && curr->left == NULL){
			free(curr);
			return NULL;
		}
		
		else if(curr->right == NULL || curr->left == NULL){
			Tree* temp;
			if(curr->left) temp = curr->left;
			else temp = curr->right;
			
			free(curr);
			return temp;
		}
		
		else{
			Tree* temp = findMax(curr->left);
			curr->val = temp->val;
			curr->left = pop(curr->left, temp->val);
		}
	}
	
	return curr;
}


int main(){
	int q;
	scanf("%d %d", &T, &q);
	For(i, T){
		scanf("%d", &n);
		root = push(root, n);
	}
	
	For(i, q){
		scanf("%d", &n);
		root = pop(root, n);
		if(root){
			printf("%d\n", findMax(root)->val);
		}else{
			puts("-1");
		}
	}
}
