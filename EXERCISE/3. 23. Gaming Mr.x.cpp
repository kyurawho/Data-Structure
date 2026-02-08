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
	char name[105];
	char namer[105];
	int rate;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(char name[], char namer[], int rate){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	strcpy(node->name, name);
	strcpy(node->namer, namer);
	node->rate = rate;
	
	node->left = node->right = NULL;
	
	return node;
}

Tree* search(Tree* curr, char name[]){
	if(curr == NULL) return NULL;
	else if(strcmp(curr->name, name) < 0) return search(curr->left, name);
	else if(strcmp(curr->name, name) > 0) return search(curr->right, name);
	return curr;
}

Tree* push(Tree* curr, char name[], char namer[], int rate){
	if(curr == NULL){
		curr = createNode(name, namer, rate);
	}
	
	else if(strcmp(curr->name, name) != 0){
		if(strcmp(curr->name, name) < 0){
			curr->left = push(curr->left, name, namer, rate);
		}else{
			curr->right = push(curr->right, name, namer, rate);
		}
	}
	
	return curr;
}

void inOrder(Tree* curr){
	if(curr->left) inOrder(curr->left);
	printf("%s - %d\n", curr->namer, curr->rate);
	if(curr->right) inOrder(curr->right);
}

Tree* findMax(Tree* curr){
	if(curr == NULL) return NULL;
	if(curr->right == NULL) return curr;
	return findMax(curr->right);
}

Tree* pop(Tree* curr, char name[]){
	if(curr == NULL) return NULL;
	else if(strcmp(curr->name, name) < 0) pop(curr->left, name);
	else if(strcmp(curr->name, name) > 0) pop(curr->right, name);
	else{
		// no child
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		
		// 1 child
		else if(curr->left != NULL || curr->right != NULL){
			Tree* temp;
			if(curr->left){
				temp = curr->left;
			}else{
				temp = curr->right;
			}
			free(curr);
			return temp;
		}
		
		// 2 child
		else{
			Tree* temp = findMax(curr->left);
			strcpy(curr->name, temp->name);
			curr = pop(curr->left, temp->name);
		}
	}
}

int main(){
	int ch = -1;
	
	while(ch != 3){
		puts("1. Insert");
		puts("2. Delete");
		puts("3. Exit");
		
		scanf("%d", &ch);
		
		switch(ch){
			case 1:{
				char namer[105];
				int rate;
				printf("Input name: ");
				do{
					scanf(" %[^\n]", namer);	
				}while(strlen(namer) <= 0 || strlen(namer) > 100);
				
				do{
					printf("Input rate: ");
					scanf(" %d", &rate);
				}while(rate <= 0 || rate > 10);
				
				char name[105];
				For(i, strlen(name)){
					name[i] = tolower(namer[i]);
				}
				
				Tree* res = search(root, namer);
				if(res){
					res->rate = rate;
					break;
				}
				
				root = push(root, name, namer, rate);
				break;
			}
			case 2:{
				char namer[100];
				printf("Input name: ");
				do{
					scanf(" %[^\n]", namer);	
				}while(strlen(namer) < 0 || strlen(namer) > 100);
				
				char name[105];
				For(i, strlen(name)){
					name[i] = tolower(namer[i]);
				}
				
				Tree* res = search(root, name);
				if(res){
					root = pop(root, name);
					puts("Delete successfully");
					break;
				}
				
				printf("Not found\n");
				break;
			}
			case 3:{
				puts("Exiting...");
				break;
			}
			default:{
				puts("Invalid format");
				break;
			}
		}
	}
}
