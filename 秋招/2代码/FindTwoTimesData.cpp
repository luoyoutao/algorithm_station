#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<unordered_map>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
/**
 * 功能：在数组中查找出现奇数次的两个数
 * 参数：带查找的数组，数组长度
 * 返回值：这两个数的容器
 * 时间：2022.09.24
 */ 
vector<int> FindTwoTimesData(vector<int>& arr, int len) {
    vector<int>ans;
    int t = 0;
    for(int i = 0;i < len;i ++) {
        t ^= arr[i];
    }
    int k = lowbit(t);
    int m = 0, n = 0;
    for(int i = 0;i < len;i ++) {
        if(k & arr[i]) {
            m ^= arr[i];
        } else {
            n ^= arr[i];
        }
    }
    ans.push_back(m);
    ans.push_back(n);
    return ans;
}

/**
 * 功能：在数组中查找出现奇数次的两个数
 * 参数：带查找的数组，数组长度
 * 返回值：这两个数的容器
 * 时间：2022.09.24
 */
vector<int> ControlGroup(vector<int>& arr, int len) {
    unordered_map<int, int>m;
    for(int i = 0;i < len;i ++) {
        if(m.count(arr[i])) {
            m[arr[i]] ++;
        } else m[arr[i]] = 1;
    }
    vector<int>ans;
    for(auto v : m) {
        if(v.second % 2 == 1) {
            ans.push_back(v.first);
        } 
    }
    return ans;
}

/**
 * 功能：生成只有两种数出现奇数次，其他数均出现偶数次的数组
 * 参数：待生成的数组
 * 返回值：void 
 * 时间：2022.09.24
 */ 
void ProducesimpleData(vector<int>& arr) {
    srand(time(0));
    /* 为了不让次数太大，就对10000取了个模 */
    int a = rand() % 10000;
    int b = rand() % 10000;
    int c = rand() % 10000;
    int a_times = a % 2 > (a + 1) % 2 ? a : a + 1;  // 第一个数出现的奇数次的次数
    int b_times = b % 2 > (b + 1) % 2 ? b : b + 1;  // 第二个数出现的奇数次的次数
    int c_times = c % 2 > (c + 1) % 2 ? c  + 1: c;  // 其他数出现的偶数次的次数
    int t = rand();
    for(int i = 0;i < a_times;i ++) {  // 生成第一个出现奇数次的数
        arr.push_back(t);
    }
    t = rand();
    for(int i = 0;i < b_times;i ++) {  // 生成第二个出现奇数次的数
        arr.push_back(t);
    }
    int n = rand() % 5000;  // 生成出现偶数次的数的种类
    while(n --) {
        t = rand();
        for(int i = 0;i < c_times;i ++) {  // 生成每一个个出现偶数次的数
            arr.push_back(t);
        }
    }
}

/**
 * 功能：测试FindTwoTimesData()算法的正确性
 * 参数：被测试的数组
 * 返回值：是否正确
 * 时间：2022.09.25
 */
bool Test(vector<int>& arr) {
    ProducesimpleData(arr);
    int len = arr.size();
    vector<int>a = FindTwoTimesData(arr, len);
    vector<int>b = ControlGroup(arr, len);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[0] == b[0] && a[1] == b[1]) {
        return true;
    } else return false;
}

int main()
{
    vector<int>arr;
    bool re = Test(arr);
    if(re) {
        cout << "算法正确" << endl;
    } else {
        cout << "算法有误" << endl;
    }
    system("pause");
    return 0;
}
