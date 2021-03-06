#include<bits/stdc++.h>
using namespace std;

void insertionSortRec(int arr[], int len) {
	if (len <= 1)
		return;

	insertionSortRec(arr, len - 1);

	int key = arr[len - 1];
	int pos = len - 2;
	while (pos >= 0 and arr[pos] > key) {
		arr[pos + 1] = arr[pos];
		pos--;
	}
	arr[pos + 1] = key;
}

void insertionSort(int arr[], int n) {
	int key;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		int j = i - 1;
		while (j >= 0 and arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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