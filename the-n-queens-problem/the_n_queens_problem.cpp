//N皇后问题
//输入皇后数量
//输出棋盘解法
#include"the_n_queens_problem.h"

int N;            //存储皇后个数的变量
int num = 0;      //初始化种数为0

int main() {
    stack<int> queen;

    cout << "现有N*N的棋盘，放入N个皇后，要求所有皇后不在同一行、列、和同一斜线上！\n请输入皇后个数 N:";
    cin >> N;                                   //输入皇后的个数
    queen.placeQueen(0);                        //开始放置
    cout << "共有" << num << "种解法!" << endl;  //输出解法总数
    return 0;
}

template<class T>
void stack<T>::push(T q) {
    if (top >= maxSize - 1) throw "error";
    else {
        top++;                 //栈顶指针上移
        data[top] = q;
    }
}

template<class T>
void stack<T>::pop() {
    if (isEmpty()) throw "error";
    else top--;               //站定指针下移
}

template<class T>
bool stack<T>::judgement() {
    for (int i = 0; i < top; i++)//遍历前面各个皇后的位置
        if (data[top] == data[i] || abs(data[top] - data[i]) == top - i)//如果列值相等或者行差与列差相等
            return false;
    return true;
}

template<class T>
void stack<T>::display() {
    cout << "第" << num << "种解法:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < data[i]; j++)
            cout << "0\t";     //不放置皇后
        cout << "x\t";         //放置皇后
        for (int j = N - 1; j > data[i]; j--)
            cout << "0\t";     //不放置
        cout << '\n' << endl;
    }
    cout << endl;
}

template<class T>
void stack<T>::placeQueen(int row) {
    for (int i = 0; i < N; i++)     //对棋盘的列进行遍历
    {
        push(i);                    //入栈
        if (judgement())            //判断能否放下
        {
            if (row < N - 1)        //是否是最后一个皇后
                placeQueen(row + 1);//还未到最后一个皇后， 则递归
            else {
                num++;              //方案个数计数加一
                display();          //打印棋盘
            }
        }
        pop();                      //若不能放下则出栈
    }
}

template<class T>
bool stack<T>::isEmpty() {  //判断栈是否为空
    if (top == -1)return true;
    else return false;
};