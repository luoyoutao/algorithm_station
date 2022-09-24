#include<iostream>
using namespace std;
void InsertSort(int arr[], int len) {
	for(int i = 1;i < len;i ++) {
		int k = arr[i];
		int j = i - 1;
		while(k < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			j --;
		}
		arr[j + 1] = k;
	}
}
