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

int size = 10;

typedef struct Node{
	char id[10];
	char name[20];
	char major[50];
	int classNum;
	int year;
	struct Node* next;
}Node;

Node* head[10] = {NULL};
Node* curr = NULL;

Node* createNode(char id[], char name[], char major[], int classNum, int year){
	Node* node = (Node*)malloc(sizeof(Node));
	
	strcpy(node->id, id);
	strcpy(node->name, name);
	strcpy(node->major, major);
	node->classNum = classNum;
	node->year = year;
	
	node->next = NULL;
	
	return node;
}

int hash(char id[]){
	int total = 0;
	
	For(i, strlen(id)){
		total += id[i];
	}
	
	return total % size;
}

void push(char id[], char name[], char major[], int classNum, int year){
	Node* node = createNode(id, name, major, classNum, year);
	
	int key = hash(id);
	
	if(head[key] == NULL){
		head[key] = node;
	}else{
		node->next = head[key];
		head[key] = node;
	}
}

void pop(char id[]){
	int key = hash(id);
	
	if(head[key] == NULL){
		puts("Not found!");
	}
	
	if(strcmp(head[key]->id, id) == 0){
        Node* temp = head[key];
        head[key] = head[key]->next;
		printf("Sucessfully delete %s\n", temp->id);
        free(temp);
        return;
    }
	
	curr = head[key];
	while(curr->next && strcmp(curr->next->id, id) != 0){
		curr = curr->next;
	}
	
	if(curr->next == NULL){
		puts("Not found!");
		return;
	}	
	
	Node* temp = curr->next;
	curr->next = curr->next->next;
	printf("Sucessfully delete %s\n", temp->id);
	free(temp);
}

void insert(){
	char id[10], name[20], major[50];
	int classNum, year;
	
	do{
		printf("Insert name (1 - 15): ");
		scanf(" %s", name);
		getchar();
	}while(strlen(name) < 1 || strlen(name) > 15);
	
	do{
		printf("Insert major (Compsci, Marketing, Architect): ");
		scanf(" %s", major);
		getchar();
		
		For(i, strlen(major)) major[i] = tolower(major[i]);
	}while(strcmp(major, "compsci") != 0 &&
	strcmp(major, "marketing") != 0 &&
	strcmp(major, "architect") != 0);
	
	do{
		printf("Insert number of class (20 - 24): ");
		scanf("%d", &classNum);
		getchar();
	}while(classNum <= 19 || classNum >= 25);
	
	do{
		printf("Insert admission year (2024 - 2026): ");
		scanf("%d", &year);
		getchar();
	}while(year < 2024 || year > 2026);
	
	id[0] = toupper(major[0]);
	id[1] = toupper(major[1]);
	id[2] = toupper(major[2]);
	for(int i = 3; i < 6; i++){
		id[i] = rand() % 10 + '0';
	}
	
	printf("ID: %s\n", id);
	printf("Name: %s\n", name);
	printf("Major: %s\n", major);
	printf("Class Number: %d\n", classNum);
	printf("Admission year: %d\n", year);
	
	push(id, name, major, classNum, year);
}

bool flags = true;

void view(){
	bool flag = true;
	
	For(i, 10){
		curr = head[i];
		
		if(curr){
			flag = false;
			flags = false;
		}
	}
	
	if(flag){
		puts("Empty table");
		return;
	}
	
	For(i, 10){
		curr = head[i];
		
		printf("Table %d\n", i + 1);
		
		int cnt = 1;
		while(curr){
			printf("%d.\n", cnt++);
			printf("ID: %s\nName: %s\nMajor: %s\nClass Number: %d\nAdimission Year: %d\n", curr->id, curr->name, curr->major, curr->classNum, curr->year);
			curr = curr->next;
		}
	}
}

void del(){
	view();
	if(flags) return;
	
	char id[10];
	
	printf("Input ID >> ");
	scanf("%s", id);
	getchar();
	if(id[0] == '0') return;
	
	pop(id);
}

int main(){
	srand(time(NULL));
	int ch = -1;
	while(ch != 4){
		puts("1. Insert Mahasiswa");
		puts("2. View Mahasiswa");
		puts("3. Delete Mahasiswa");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &ch);
		getchar();
		
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				view();
				break;
			case 3:
				del();
				break;
			case 4:
				puts("Exiting...");
				getchar();
				break;
			default:
				puts("Invalid input");
				break;
		}
	}
}
