#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
typedef long long ll;

typedef struct Node{
	int val;
	struct Node* next;
}Node;


Node* head = NULL;
Node* tail = NULL;
Node* curr = NULL;

Node* createNode(int val){
	Node* node = (Node*) malloc (sizeof(Node));
	
	node->val = val;
	node->next = NULL;
	
	return node;
}

void pushHead(int val){
	Node* node = createNode(val);
	
	if(head == NULL){
		head = tail = node;
	}else{
		node->next = head;
		head = node;
	}
}

int popHead(char c){
	if(head == NULL) exit(1);
	
	int value;
	switch(c){
		case '*':
			value = head->val * head->next->val;
			break;
		case '+':
			value = head->val + head->next->val;
			break;
		case '-':
			value = head->val - head->next->val;
			break;
		case '/':
			value = head->val / head->next->val;
			break;
	}
	
	
	Node* temp = head;
	Node* temp2 = head->next;
	head = head->next->next;
	if(head == NULL) tail = NULL;
	free(temp);
	free(temp2);
	return value;
}

int main(){
	char s[] = "-*/+45323";
	
	for(int i = strlen(s) - 1; i >= 0; i--){
		if(isdigit(s[i])) pushHead(s[i] - '0');
		else pushHead(popHead(s[i]));
	}
	
	printf("%d", head->val);
}
