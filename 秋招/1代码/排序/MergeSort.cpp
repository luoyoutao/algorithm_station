
#include<iostream>
using namespace std;
void MergeSort(int arr[], int l, int r) {
	if(l >= r) return ;
	int mid = l + ((r - l) >> 1);  // 注意这里的右移一定要用圆括号括起来
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);
	int k = 0;
	int i = l;
	int j = mid + 1;
	int tmp[r - l + 1];
	while(i <= mid && j <= r) {
		if(arr[i] <= arr[j]) tmp[k ++] = arr[i ++];
		else tmp[k ++] = arr[j ++];
	}
	while(i <= mid) tmp[k ++] = arr[i ++];
	while(j <= r) tmp[k ++] = arr[j ++];
	for(int i = l, j = 0;j < k;i ++, j ++) {
		arr[i] = tmp[j];
	}
}
