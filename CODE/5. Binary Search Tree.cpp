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
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int value){
	Tree* node = (Tree*) malloc (sizeof(Tree));
	
	node->value = value;
	node->left = node->right = NULL;
	
	return node;
}

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

Tree* findMax(Tree* curr){ // Predecessor
	if(curr == NULL) return NULL;
	if(curr->right == NULL) return curr;
	
	return findMax(curr->right); // The most right value of curr tree
}

Tree* findMin(Tree* curr){ // Successor
	if(curr == NULL) return NULL;
	if(curr->left == NULL) return curr;
	
	return findMax(curr->left); // The most left value of curr tree
}

Tree* push(Tree *curr, int value){
	// Base Case
	if (curr == NULL){
		curr = createNode(value);
	}
	
	// Recursive Case
	else if (curr->value != value){
		if (value < curr->value){ // Left node
			curr->left = push (curr->left, value);
		}else{ // Right node
			curr->right = push (curr->right, value);
		}	
	}
	
	return curr; // Root will always be root
}

Tree* pop (Tree *curr, int value){
	// Base Case
	if (curr == NULL){
		return NULL;
	}
	
	else if (value > curr->value){ // continue searching to right node
		curr->right = pop(curr->right, value);
	} else if (value < curr->value){ // continue searching to left node
		curr->left = pop(curr->left, value);
	}

	else {
		// No Child
		if (curr->left == NULL && curr->right == NULL){
			free (curr); //free the curr to avoid memory leaking
			return NULL;
		}
		
		// 1 Child
		else if (curr->left == NULL || curr->right == NULL){
			Tree *temp;
			if (curr->left){ // left is not NULL
				temp = curr->left; // curr->left is a child from target
			}else{ // right is not NULL
				temp = curr->right; // curr->right is a child from target
			}
			free(curr); //free the curr to avoid memory leaking
			return temp;
		}
		
		// 2 Children
		else if (curr->left && curr->right) {
			// Search predecessor or successor
			// Find the largest value of its left subtree (predecessor)
			// Find the smallest value of its right subtree (successor)
			Tree* temp = findMax(curr->left); // predecessor
			curr->value = temp->value; // change root->value to predecessor
			curr->left = pop(curr->left, temp->value);	// delete predecessor
		}
	}
	
	return curr; // Root will always be root
}

int main(){
	root = push(root, 65);
	root = push(root, 76);
	root = push(root, 35);
	root = push(root, 72);
	root = push(root, 86);
	root = push(root, 91);
	
	inOrder(root);
	puts("");
	Tree* result = search(root, 91);
	
	root = pop(root, 35);
	inOrder(root);
	puts("");
}
