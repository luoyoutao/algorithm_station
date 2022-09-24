#include<iostream>
using namespace std;
/**
 * 功能：在有序数组中查找某个数
 * 参数：带查找数组、查找元素、左边界、右边界
 * 返回值：查找成功返回位置，否则返回-1 
 */
int search(int arr[], int k, int l, int r) {
    if(l > r) return -1;
    int mid = l + ((r - l) >> 1);
    if(arr[mid] == k) {
        return mid;
    } else if(k > arr[mid]) {
        return search(arr, k, mid + 1, r);
    } else {
        return search(arr, k, l, mid - 1);
    }
}
