#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int i, int n) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n and arr[left] > arr[largest])
		largest = left;
	if (right < n and arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, largest, n);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, i, n);
	}
	// the first element of the array is the max element
	// so get that element as result and swap it with last element
	// now call heapity for the first element
	for (int i = n - 1; i > 0; i--) {
		swap(arr[i], arr[0]);
		heapify(arr, 0, i);
	}
}


void solution() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	heapSort(arr, n);
	for (int i = 0; i < n; i++) {
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