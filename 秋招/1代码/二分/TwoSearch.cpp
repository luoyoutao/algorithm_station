#include<iostream>
using namesapce std;
/**
 * 功能：查找>=k最最侧的位置
 * 参数：带查找数组、左边界、有右边界
 * 返回值：找到的位置
 * 时间：2022.09.24 
*/
int SearchOne(int arr[], int k, int l, int r) {
    while(l < r) {
        int mid = l + ((r - l) >> 1);
        if(arr[mid] >= k) {  // 往满足>=k的左边找
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
/**
 * 功能：查找<=k最右侧的位置
 * 参数：带查找数组、左边界、有右边界
 * 返回值：找到的位置
 * 时间：2022.09.24 
*/   
int SearchTwo(int arr[], int k, int l, int r) {
    while(l < r) {
        int mid = r + l + 1 >> 1;
        if(arr[mid] <= k) {  // 往满足<=k的右边找
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
