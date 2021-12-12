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



void insertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int pos = i - 1;
		while (pos >= 0 and arr[pos] > key) {
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = key;
		cout << "Iteration: " << i << endl;
		for (int k = 0; k < len; k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}




void solution() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// insertionSort(arr, n);
	insertionSortRec(arr, n);
	cout << "Sorted array is:\n";
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