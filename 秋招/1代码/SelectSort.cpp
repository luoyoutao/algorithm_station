#include<iostream>
using namespace std;
void Swap(int& a, int& b) {  // 交换a、b的值. 需注意a、b不能指向同一块内存，且这里需要用指针或者引用
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void SelectSort(int arr[], int len) {
	for(int i = 0;i < len - 1;i ++) {
		for(int j = i + 1;j < len;j ++) {  // 从[i, len)中选择最小的数往放到i位置
			if(arr[j] < arr[i]) {
				Swap(arr[i], arr[j]);
			}
		}
	}
}



