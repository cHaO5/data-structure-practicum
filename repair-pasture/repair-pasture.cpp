//修理牧场
//根据输入的木头数量与长度，输出锯木头的最小花费
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

void read(priority_queue<int, vector<int>, greater<int> > &farmer, int n) {
    cout << "请依次输入木头长度：";
    int m = 0, count = 0;   //逐个读取木头长度
    while (count < n) {
        cin >> m;
        if (m >= 0) {
            farmer.push(m);
            count++;
        } else {            //不符合要求的输入
            cout << m << "不符合要求， 请重新输入" << endl;
        }
    }
}

int main() {      //带权路径长度，即哈夫曼树
    priority_queue<int, vector<int>, greater<int> > farmer;

    cout << "请输入n值：";
    int n = 0;    //n是要把木头锯成的数量
    cin >> n;

    read(farmer, n);

    int sum = 0;                       //优先队列模拟哈弗曼树
    while (farmer.size() > 1) {
        int first = farmer.top();
        farmer.pop();
        int second = farmer.top();
        farmer.pop();
        sum += first + second;        //每次取队列前2个，即最小的2个数相加
        farmer.push(first + second);  //和重新推入优先队列
    }

    cout << "最小花费是" << sum << endl;
    return 0;
}
