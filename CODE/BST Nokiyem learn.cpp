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
	int phone;
	int price;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* root = NULL;

Tree* createNode(int phone, int price){
	Tree* node = (Tree*)malloc(sizeof(Tree));
	
	node->phone = phone;
	node->price = price;
	
	node->left = node->right = NULL;
	
	return node;
}

int getHeight(Tree* curr){
	if(curr == NULL) return -1;
	
	int left = getHeight(curr->left);
	int right = getHeight(curr->right);
	
	return max(left, right) + 1;
}

Tree* search(Tree* curr, int phone){
	if(curr == NULL) return NULL;
	if(curr->phone == phone) return curr;
	
	if(phone < curr->phone) return search(curr->left, phone);
	return search(curr->right, phone);
}

Tree* findMax(Tree* curr){ //predecessor
	if(curr == NULL) return NULL;
	if(curr->right == NULL) return curr;
	
	return findMax(curr->right);
}

Tree* findMin(Tree* curr){ //predecessor
	if(curr == NULL) return NULL;
	if(curr->left == NULL) return curr;
	
	return findMin(curr->left);
}

Tree* push(Tree* curr, int phone, int price){
	if(curr == NULL){
		curr = createNode(phone, price);
	}
	
	else if (curr->phone != phone){
		if(phone < curr->phone){
			curr->left = push(curr->left, phone, price);
		}else{
			curr->right = push(curr->right, phone, price);
		}
	}
	
	return curr;
}

Tree* pop(Tree* curr, int phone){
	// base case
	if(curr == NULL) return NULL;
	
	//search
	else if(phone < curr->phone){
		curr->left = pop(curr->left, phone);
	}else if(phone > curr->phone){
		curr->right = pop(curr->right, phone);
	}
	
	// pop
	else{
		// 0 child
		if(curr->left == NULL && curr->right == NULL){
			free(curr);
			return NULL;
		}
		// 1 child
		else if(curr->left == NULL || curr->right == NULL){
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
			Tree* temp = findMax(curr->left); //search predecessor
			curr->phone = temp->phone; //curr->phone itu nilai yang mau kita hapus, ga langsung dihapus
			// tapi diganti dengan nilai predecessornya.
			curr->price = temp->price;
			curr->left = pop(curr->left, temp->phone);
		}
	}
	return curr;
}

void inOrder(Tree* curr){
	if(curr->left) inOrder(curr->left);
	printf("-N%d [ $ %d ]\n", curr->phone, curr->price);
	if(curr->right) inOrder(curr->right);
}

void preOrder(Tree* curr){
	printf("-N%d [ $ %d ]\n", curr->phone, curr->price);
	if(curr->left) preOrder(curr->left);
	if(curr->right) preOrder(curr->right);
}

void postOrder(Tree* curr){
	if(curr->left) postOrder(curr->left);
	if(curr->right) postOrder(curr->right);
	printf("-N%d [ $ %d ]\n", curr->phone, curr->price);
}

int main(){
	int ch = -1;
	
	while(ch != 4){
		puts("1. Add New Phone");
		puts("2. Update Phone Price");
		puts("3. InOrder, PreOrder, PostOrder");
		puts("4. Exit");
		
		printf(">> ");
		scanf("%d", &ch);
		getchar();
		
		int phone, price;
		char s[10];
		
		switch(ch){
			case 1:{
				do{
					phone = 0;
					scanf("%s", s);
					for(int i = 1; s[i] != '\0'; i++){
						phone = phone * 10 + (s[i] - '0');
					}
				}while(s[0] != 'N' || phone < 1000 || phone > 9999);
				
				if(search(root, phone) != NULL){
					puts("--- Add New Phone Failure ---");
					break;
				}
				
				do{
					price = 0;
					scanf("%s", s);
					for(int i = 1; s[i] != '\0'; i++){
						price = price * 10 + (s[i] - '0');
					}
				}while(s[0] != '$' || price < 50 || price > 999);
				
				if(getHeight(root) >= 4){
					puts("--- Maximum Tree Level is 4 ---");
					while(root) root = pop(root, root->phone);
				}
				
				root = push(root, phone, price);
				puts("Succes");
				break;
			}
			case 2:{
				do{
					phone = 0;
					scanf("%s", s);
					for(int i = 1; s[i] != '\0'; i++){
						phone = phone * 10 + (s[i] - '0');
					}
				}while(s[0] != 'N' || phone < 1000 || phone > 9999);
				
				Tree* result = search(root, phone);
				
				if(result == NULL){
					puts("gagal bos");
					break;
				}
				
				do{
					price = 0;
					scanf("%s", s);
					for(int i = 1; s[i] != '\0'; i++){
						price = price * 10 + (s[i] - '0');
					}
				}while(s[0] != '$' || price < 50 || price > 999);
				
				result->price = price;
				
				puts("yes");
				
				break;
			}
			case 3:{
				if(root == NULL){
					puts("Kosong");
					break;
				}
				
				puts("Preorder :");
				preOrder(root);
				puts("\nInorder :");
				inOrder(root);
				puts("\nPostorder :");
				postOrder(root);
				break;
			}
			case 4:{
				while(root) root = pop(root, root->phone);	
				puts("Exiting...");
				break;
			}
			default:{
				
				break;
			}
		}
	}
}
