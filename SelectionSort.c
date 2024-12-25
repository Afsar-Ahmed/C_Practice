#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
int arr[SIZE];

void selectSort(int a[]) {
	for (int j = 0; j < SIZE-1; j++) {
		int iMin = j;
		for (int i = j+1; i < SIZE; i++) {
			if (a[i] < a[iMin]) {
				iMin = i;
			}
		}
		if (iMin != j) {
			swap(&a[j], &a[iMin]);
		}
	}
}








void printArray(int arr[]) {
	printf("Print:");
	printf("======\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}
}


int main(int argc, char** argv) {
	//randomly generated values



	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % (10 - 1 + 1) + 1;
	}

	printArray(arr);
	selectSort(arr);
	printArray(arr);


}