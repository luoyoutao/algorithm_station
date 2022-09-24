#include<iostream>
using namespace std;
void Swap(int& a, int& b) {  // 交换a、b的值. 需注意a、b不能指向同一块内存
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void BubbleSort(int arr[], int len) {
	for(int i = 0;i < len;i ++) {
		for(int j = 1;j < len - i;j ++) {
			if(arr[j - 1] > arr[j]) {
				Swap(arr[j - 1], arr[j]);
			}
		}
	}
}
