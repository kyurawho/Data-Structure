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
	int l;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int val, int l){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->val = val;
	node->l = l;
	
	node->left = node->right = NULL;
	
	return node;
}

Tree* push(Tree* curr, int val, int l){
	if(curr == NULL) curr = createNode(val, l);
	
	else if(val != curr->val){
		if(val < curr->val) curr->left = push(curr->left, val, l + 1);
		else curr->right = push(curr->right, val, l + 1);
	}
	
	return curr;
}

int getHeight(Tree* curr){
	if(curr == NULL) return 0;
	
	int left = getHeight(curr->left);
	int right = getHeight(curr->right);
	
	return max(left, right) + 1;
}

int ans = 0;

void display(Tree* curr, int h){
	if(curr->left) display(curr->left, h);
	if(curr->l == h) ans++;
	if(curr->right) display(curr->right, h);
}

bool isBalanced(Tree* root){
	int left = (root->left) ? getHeight(root->left):0;
	int right = (root->right) ? getHeight(root->right):0;
	
	if(abs(left - right) <= 1) return 1;
	return 0;
}	

int main(){
	scanf("%d", &n);
	while(n--){
		int val;
		scanf("%d", &val);
		root = push(root, val, 1);
	}
	
	if(isBalanced(root)) printf("YES\n");
	else printf("NO\n");
}
