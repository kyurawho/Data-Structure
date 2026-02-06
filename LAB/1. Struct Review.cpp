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

typedef struct Datadiri{
	char nama[100];
	char status[100];
	int age;
} dataDiri;

int main(){
	//scanf("%d", &n);

	//scanf("%d", &T);
	//while(t--){
	//
  	//}
	
//	Fori(t, T){
//		printf("Case #%d: ", t);
//	}

	dataDiri orangA;
	strcpy(orangA.nama, "David");
	strcpy(orangA.status, "Mahasiswa");
	orangA.age = 18;
	
	dataDiri arr[100] = {{"Felix", "Mahasiswa", 18}, {"Louis", "Partner", 18}};
	
	for(int i = 0; sizeof(arr) / sizeof(arr[0]); i++){
		printf("Nama saya %s status saya %s saya berumur %d tahun\n", arr[i].nama, arr[i].status, arr[i].age);	
	}
	
}
