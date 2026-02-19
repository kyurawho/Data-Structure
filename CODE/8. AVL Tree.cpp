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
#define max(A,B) (A > B ? A:B) // this is important !!

// THE TEMPLATE

typedef struct Tree{
	int value;
	int height;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int value){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->value = value;
	node->height = 1;
	
	node->left = node->right = NULL;
	
	return node;
}

// HELPER FUNCTION

int height(Tree* curr){
	if(!curr) return 0;
	return curr->height;
}

int getBalance(Tree* curr){
	if(!curr) return 0;
	return height(curr->left) - height(curr->right);
}

// PREDECESSOR & SUCCESSOR

Tree* findMax(Tree* curr){
	while(curr->right) curr = curr->right;
	return curr;
}

Tree* findMin(Tree* curr){
	while(curr->left) curr = curr->left;
	return curr;
}

// ROTATION FUNCTION (LEFT AND RIGHT)

Tree* leftRotate(Tree* x){
	Tree* y = x->right;
	Tree* T2 = y->left;
	
	// Perform rotation
	y->left = x;
	x->right = T2;
	
	// Update height
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return y;
}

/*
        x
       / \
      T1  y
         / \
        T2  T3
        
        |
        |
        v
        
        y
       / \
      x   T3
     / \
    T1  T2
*/

Tree* rightRotate(Tree* y){
	Tree* x = y->left;
	Tree* T2 = x->right;
	
	// Perform rotation
	x->right = y;
	y->left = T2;
	
	// Update height
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	
	return x;
}

/*
        y
       / \
      x   T4
     / \
    T1  T2
       
       |
       |
       |
       v
    
        x
       / \
      T1  y
         / \
        T2  T4
*/

// CORE FUNCTION OF AVL TREE

Tree* push(Tree* curr, int value){
	// Base Case
	if(curr == NULL){
		curr = createNode(value);
	}
	
	else if(value != curr->value){
		if(value < curr->value) curr->left = push(curr->left, value);
		else curr->right = push(curr->right, value);
	}
	
	// Update height
	curr->height = max(height(curr->left), height(curr->right)) + 1;
	
	int balance = getBalance(curr);
	
	// Case to rotate
	// LL
	if(balance > 1 && value < curr->left->value){
		return rightRotate(curr);
	}
	
	// RR
	if(balance < -1 && value > curr->right->value){
		return leftRotate(curr);
	}
	
	// LR
	if(balance > 1 && value > curr->left->value){
		curr->left = leftRotate(curr);
		return rightRotate(curr);
	}
	
	// RL
	if(balance < -1 && value < curr->right->value){
		curr->right = rightRotate(curr);
		return leftRotate(curr);
	}
	
	return curr;
}

Tree* pop(Tree* curr, int value){
	// Base Case
	if(curr == NULL) return NULL;
	
	// Search
	else if(value < curr->value) curr->left = pop(curr->left, value);
	else if(value > curr->value) curr->right = pop(curr->right, value);
	
	else{
		// No Child
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		
		// 1 child
		else if(curr->left == NULL || curr->right == NULL){
			Tree* temp;
			if(curr->left) temp = curr->left;
			else temp = curr->right;
			free(curr);
			return temp;
		}
		
		// 2 child
		else if(curr->left && curr->right){
			Tree* temp = findMax(curr->left);
			curr->value = temp->value;
			curr->left = pop(curr->left, temp->value);
		}
	}
	
	// Update height
	curr->height = max(height(curr->left), height(curr->right)) + 1;
	
	int balance = getBalance(curr);
	
	// Case to rotate
	// LL
	if(balance > 1 && getBalance(curr->left) >= 0){
		return rightRotate(curr);
	}
	
	// RR
	if(balance < -1 && getBalance(curr->right) < 0){
		return leftRotate(curr);
	}
	
	// LR
	if(balance > 1 && getBalance(curr->left) < 0){
		curr->left = leftRotate(curr);
		return rightRotate(curr);
	}
	
	// RL
	if(balance < -1 && getBalance(curr->right) >= 0){
		curr->right = rightRotate(curr);
		return leftRotate(curr);
	}
	
	return curr;
}

// ANYTHING YOU MAY NEED

Tree* search(Tree* curr, int value){
  if(curr == NULL) return NULL; // Not found
  if(value == curr->value) return curr; // Found the value
  if(value < curr->value) return search(curr->left, value); // If value is smaller
  return search(curr->right, value); // If value is greater
}

void inOrder(Tree* curr){
  if(curr->left) inOrder(curr->left);
  printf("%d ", curr->value);
  if(curr->right) inOrder(curr->right);
}

void preOrder(Tree* curr){
  printf("%d ", curr->value);
  if(curr->left) preOrder(curr->left);
  if(curr->right) preOrder(curr->right);
}

void postOrder(Tree* curr){
  if(curr->left) postOrder(curr->left);
  if(curr->right) postOrder(curr->right);
  printf("%d ", curr->value);
}

int main(){
	
}
