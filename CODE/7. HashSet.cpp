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

const int SIZE = 25;

char hash[SIZE];

int key (int value) {
	return (value % SIZE);
}

void push(int value){
	int index = key(value);
	int temp = index;
	
	if (hash[index] == NULL){ // Still available
		hash[index] = value;
	}
	
	else {
		while (hash[index] != NULL){
			index++;
			if (index >= SIZE-1){ // Reach max size case
				index = 0;
			}
			if (index == temp) { // Looping case
				return;
			}
		}
		hash[index] = value; // assign the value
	}	
}

void pop(int value){
	int index = key(value);
	int temp = index;
	
	if (hash[index] == value){ // no need linear probing
		hash[index] = NULL;
	}
	
	else {
		while (hash[index] != value){
			index++;
			if (index >= SIZE-1){ // reach max size
				index = 0;
			}
			if (index == temp) { // looping case
				return;
			}
		}
		hash[index] = NULL; // assign the value
	}
}

int main(){
	push(1);
	push(1);
	push(1);
	push(1);
	
	pop(1);
	pop(1);
	
	For(i, SIZE){
		printf("%d\n", hash[i]);
	}
}
