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
	int depth;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int value, int depth){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->value = value;
	node->depth = depth;
	node->left = node->right = NULL;
	
	return node;
}

Tree* push(Tree* curr, int value, int depth){
	if(curr == NULL){
		curr = createNode(value, depth);
	}
	
	else if(curr->value != value){
		if(value < curr->value){
			curr->left = push(curr->left, value, depth + 1); 
		}else{
			curr->right = push(curr->right, value, depth + 1);
		}
	}
	
	return curr;
}

int getHeight(Tree* curr){
	if(curr == NULL) return 0;
	
	int left = getHeight(curr->left);
	int right = getHeight(curr->right);
	
	return max(left, right) + 1;
}

ll ans = 1;

void display(Tree* curr, int height){
	if(curr->left) display(curr->left, height);
	if(curr->depth == height) ans *= curr->value;
	if(curr->right) display(curr->right, height);
}

int main(){
	scanf("%d", &T);
	
	while(T--){
		scanf("%d", &n);
		root = push(root, n, 1);
		int depth = getHeight(root);
		ans = 1;
		display(root, depth);
		
		printf("%lld\n", ans);
	}
}
