#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void ProduceRandomSample(int arr1[], int arr2[], int len) {  // 生成随机数组
	const int max_value = (int)1e10;  // 生成随机数的最大值
	srand(time(0));                   // 设置随机种子，在调用rand()之前
	for(int i = 0;i < len;i ++) {
		int tmp = rand() % max_value - rand() % max_value;
		arr1[i] = tmp;
		arr2[i] = tmp;
	}
}
bool Test(int arr1[], int arr2[], int len) {  // 验证算法是否正确，这里假设a算法是正确的
	MergeSort(arr1, 0, len - 1);  // a算法
	QuickSort(arr2, 0, len - 1);  // b算法
	for(int i = 0;i < len;i ++) {
		if(arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}
int main()
{
	int len = 500;    // 数组长度
	int arr1[len];    // 数组不能在函数中声明再返回，否则函数结束数组就被释放
	int arr2[len];    // 第二个数组
	int times = 1000;    // 测试次数
	bool is_right = true;
	while(times --) {	
		ProduceRandomSample(arr1, arr2, len);  // 生成随机数
		if(!Test(arr1, arr2, len)) {
			is_right = false;
			break;
		}
	}
	if(is_right) cout << "算法正确！" << endl;
	else cout << "算法有误！" << endl;
	system("pause");
	return 0;
}
