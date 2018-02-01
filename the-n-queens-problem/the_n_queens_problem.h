#include<iostream>
#include <cmath>

using namespace std;

const int maxSize = 1000;    //定义栈的最大值

template<class T>
class stack                  //定义顺序栈模板类
{
public:
    stack() { top = -1; };   //构造函数，初始化一个空栈
    void push(T q);          //入栈
    void pop();              //出栈
    bool judgement();        //判断是否在同一行、同一列、同一斜线
    void display();          //输出棋盘
    bool isEmpty();          //判断栈是否为空
    void placeQueen(int row);//摆皇后的递归函数

private:
    T data[maxSize];         //定义栈的数组
    int top;                 //定义栈顶指针
};