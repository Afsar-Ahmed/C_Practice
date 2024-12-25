#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
int arr[SIZE];


void bubbleSort(int a[]) {
	bool swapped = true; // Did we swap?
	int temp = 0;//contaainer to hold
	while (swapped) {//
		swapped = false;
		for (int i = 0; i < SIZE - 1; i++) {
// Check if we need to swap
			if (a[i] > a[i+1]) {
// Swap two array elements
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swapped = true; // Show that a swap occurred
			}
		}
		
	}
}

void printArray(int arr[]){
	printf("Print:");
	printf("======\n");
	for (int i = 0; i < SIZE; i++){
		printf("%d\n", arr[i]);
	}
}


int main(int argc, char** argv){
	//randomly generated values
	
	
	
	for (int i = 0; i < SIZE; i++){
		arr[i] = rand() % (10 - 1 + 1) + 1;
	}
	
	printArray(arr);
	bubbleSort(arr);
	printArray(arr);
	
	
}