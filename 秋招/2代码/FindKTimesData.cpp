#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
using namespace std;

/** 
 * 功能：生成一个出现k次，多个出现m次的数的随机数组，其中k < m
 * 参数：待生成的数组
 * 返回值：k、m的容器
 * 时间：2022.09.25
 */
vector<int> ProduceSimple(vector<int>& arr) {
    srand(time(0));
    /* 为了使次数不要过大，模上10000 */
    int k = rand() % 10000 + 1;
    int m = k + rand() % 10000 + 1;
    int t = rand();  // 出现k次的数
    for(int i = 0;i < k;i ++) {
        arr.push_back(t);
    }
    int x = rand() % 500 + 1;  // 出现m次数的种类
    while(x --) {
        int tmp = rand();
        for(int i = 0;i < m;i ++) {
            arr.push_back(tmp);
        }
    }
    vector<int>re;
    re.push_back(k);
    re.push_back(m);
    return re;
}

/** 
 * 功能：对照组算法，查找出现k次的那个数
 * 参数：待查找数组、出现的次数k
 * 返回值：出现k次的那个数
 * 时间：2022.09.25
 */
int ControlGroup(vector<int>& arr, int k) {
    unordered_map<int, int>m;
    for(auto v : arr) {
        if(m.count(v)) {
            m[v] ++;
        } else {
            m[v] = 1;
        }
    }
    for(auto v : m) {
        if(v.second == k) {
            return v.first;
        }
    }
    return -1;  // 查找失败
}

/** 
 * 功能：查找出现k次的数
 * 参数：待查找的数组，出现次数m
 * 返回值：出现k次的数
 * 时间：2022.09.25
 */
int FindKTimesData(vector<int>& arr, int m) {
    int cnt[32] = {0};  // 用于存储每一位的1的个数
    for(auto v : arr) { 
        for(int i = 0;i < 32;i ++) {  // 对于每个数，分别计算每一位的1
            cnt[i] += (1 << i) & v;
            cnt[i] %= m;  // 这里一定要取模m，否则会溢出
        }
    }
    int ans = 0;
    for(int i = 0;i < 32;i ++) {
        if(cnt[i] % m != 0) {
            ans |= (1 << i);
        }
    }
    return ans;
}

/** 
 * 功能：测试算法FindKTimesData()的正确性
 * 参数：待查找数组
 * 返回值：是否正确
 * 时间：2022.09.25
 */
bool Test(vector<int>& arr) {
    int test_times = 500;  // 测试500次
    while(test_times --) {
        vector<int>km = ProduceSimple(arr);
        int re_a = FindKTimesData(arr, km[1]);
        int re_b = ControlGroup(arr, km[0]);
        if(re_a != re_b) {
            for(auto v:arr) {
                cout << v << endl;
            }
            cout << re_a << " " << re_b << endl;
            return false;
        }
        arr.clear();
    }
    return true;
}

int main()
{
    vector<int>arr;
    bool ans = Test(arr);
    if(ans) {
        cout << "算法正确" << endl;
    } else {
        cout << "算法有误" << endl;
    }
    system("pause");
    return 0;
}
