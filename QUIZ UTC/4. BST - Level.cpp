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
	int value;
	int level;
	struct Node* left;
	struct Node* right;
}Node;

Node* root = NULL;

Node* createNode(int value, int level){
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->value = value;
	node->level = level;
	
	node->left = node->right = NULL;
	
	return node;
}

Node* push(Node* curr, int value, int level){
	if(curr == NULL){
		curr = createNode(value, level);
	}
	else if(value != curr->value){
		if(value < curr->value){
			curr->left = push(curr->left, value, level + 1);
		}else{
			curr->right = push(curr->right, value, level + 1);
		}
	}
	return curr;
}

int cnt = 0;

void display(Node* curr){
	if(curr->level == cnt) printf("%d ", curr->value);
	
	if(curr->left) display(curr->left);
	if(curr->right) display(curr->right);
	
}

int getHeight(Node* curr){
	if(curr == NULL) return 0;
	
	int left = getHeight(curr->left);
	int right = getHeight(curr->right);
	
	return max(left, right) + 1;
}

int main(){
	scanf("%d", &T);
	int ans = 0;
	while(T--){
		scanf("%d", &n);
		if(n >= 80) ans++;
		root = push(root, n, 0);
	}
	
	int depth = getHeight(root);
	
	For(i, depth){
		display(root);
		printf("\n");
		cnt++;
	}
	printf("%d\n", ans);
}
