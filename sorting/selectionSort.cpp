#include<bits/stdc++.h>
using namespace std;


void selectionSort(int arr[], int n) {
	// devide the array in two part sorted and unsorted
	// take the min value from the unsorted part and put it in sorted part

	int minValueIdx;
	for (int i = 0; i < n - 1; i++) {
		minValueIdx = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minValueIdx])
				minValueIdx = j;
		swap(arr[i], arr[minValueIdx]);
	}
}

void solution() {
	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	// bubbleSort(arr, size);
	// selectionSort(arr, size);
	insertionSort(arr, size);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solution();
	return 0;
}