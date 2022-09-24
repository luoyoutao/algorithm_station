#include<iostream>
using namespace std;
void Swap(int& a, int& b) {  // 交换a、b的值. 需注意a、b不能指向同一块内存
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void QuickSort(int arr[], int l, int r) {
	if(l >= r) return ;
	int i = l - 1;
	int j = r  + 1;
	int mid = l + ((r - l) >> 1);  // 注意这里的右移，一定要用圆括号括起来
	int x = arr[mid]; 
	while(i < j) {
		do i ++;while(arr[i] < x);
		do j --;while(arr[j] > x);
		if(i < j) Swap(arr[i], arr[j]);
	}
	QuickSort(arr, l, j);
	QuickSort(arr, j + 1, r);
}
