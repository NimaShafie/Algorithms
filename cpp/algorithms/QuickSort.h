#pragma once

// Nima Shafie

#include <iostream>
using namespace std;

void QuickSort(int data[], int first, int last);
int Partition(int data[], int first, int last);
void printSemiSortedData(int data[], int first, int last, int pivotIndex);

// const variables
const int ARRAY_SIZE = 20;

void QuickMain()
{
	int data[ARRAY_SIZE];
	cout << "Quick Sort Exercise!\n\n";

	srand((unsigned)time(0));		// "seeding" random numbers

	for (int i = 0; i < ARRAY_SIZE; i++)
		data[i] = rand() % (99 - 10 + 1) + 10;

	cout << "Original Data:\n";
	for (int i = 0; i < ARRAY_SIZE; i++) cout << data[i] << " ";
	cout << endl << "\nSorting...\n" << endl;

	QuickSort(data, 0, (ARRAY_SIZE)-1);

	// outputs the final sorted data
	cout << "Sorted Data:\n";
	for (int i = 0; i < ARRAY_SIZE; i++) cout << data[i] << " ";
	cout << endl;
}

void QuickSort(int data[], int first, int last)
{
	int pivotIndex;
	if (first < last) {
		pivotIndex = Partition(data, first, last);
		printSemiSortedData(data, first, last, pivotIndex);
		QuickSort(data, first, pivotIndex - 1);
		QuickSort(data, pivotIndex + 1, last);
	}
}

int Partition(int data[], int first, int last)
{
	int pivot = data[last];
	int leftIndex = first;
	int temp = 0;

	for (int i = first; i <= last; i++) {
		if (data[i] < pivot) { // swap array elements -> i and leftInd
			temp = data[leftIndex];
			data[leftIndex] = data[i];
			data[i] = temp;
			leftIndex++;
		}
		// swap array elemnts of last and leftIndex here
		// swap pivot with larger element
		temp = data[last];
		data[last] = data[leftIndex];
		data[leftIndex] = temp;
	}
	return leftIndex;
}

void printSemiSortedData(int data[], int first, int last, int pivotIndex)
{
	for (int i = first; i < pivotIndex; i++) cout << data[i] << " ";
	cout << "Pivot Index: " << data[pivotIndex] << " ";
	for (int i = pivotIndex + 1; i <= last; i++) cout << data[i] << " ";
	cout << "\n\n";
}