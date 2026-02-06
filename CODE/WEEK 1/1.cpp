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

struct tdata{
	int age;
	char name[100];
	float score;
}a, b;

tdata x;

struct Profile{
	char name[100];
	int age;
	char address[100];
	char colour[100];
	float suhuBadan;
} profile;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swaps(char *str1, char *str2) {
    char temp[10];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];


    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (pivot > arr[j]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }


    swap(&arr[i], &arr[low]);
    return i;
}


void quickSort(int arr[], int low, int high){
    if (low < high){
        int p = partition(arr, low, high);


        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1; //size left
    int n2 = r - m; //size right


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { //strcmp(L[i], R[j]) > 0)
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;


        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);


        merge(arr, l, m, r);
    }
}

int main(){
	//scanf("%d", &n);

	//scanf("%d", &T);
	//while(t--){
	//
  	//}

//	Fori(t, T){
//		printf("Case #%d: ", t);
//	}

	int a[2];
	
	For(i, 2){
		scanf("%d", &a[i]);
	}
	
	printf("%d\n", a[0] + a[1]);
	printf("%d\n", a[0] - a[1]);
	
	int x;
	int *px, **ppx;
	px = &x;
	ppx = &px;
	*px = 10;
	
	printf("x: %d\n", x);
	printf("&x: %d\n", &x);
	printf("px: %d\n", px);
	printf("*px: %d\n", *px);
	printf("ppx: %d\n", ppx);
	printf("*ppx: %d\n", *ppx);
	printf("**ppx: %d\n", **ppx);
	
	int *pa[2];
	
	For(i, 2){
		pa[i] = &a[i];
		scanf("%d", &*pa[i]);
	}
	
	printf("%d\n", a[0] + a[1]);
	printf("%d\n", a[0] - a[1]);
	
	int x = 10;
	float f = 11.1;
	double d = 22.2;
	bool b = true;
	char c = 'c';
	char arr[INT_MAX] = {'a', 'b', 'c'};
	
	x.age = 17;
	strcpy(x.name, "andi");
	x.score = 82.5;
	
	profile.name = "Jeremy Christopher A. W.";
	profile.age = 20;
	profile.address = "Jln. in aja dulu";
	profile.colour = "Black";
	profile.suhuBadan = 36.5;
	
//	scanf("%d %d", &a, &b);
	
//	printf("%d\n", a + b);
//	printf("%d\n", a - b);
}
