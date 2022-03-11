#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
	bool swapped = false;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// cout << i << endl;
		if (not swapped)
			break;
	}
}


void solution() {
	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	bubbleSort(arr, size);
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