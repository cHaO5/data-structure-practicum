#include <iostream>

using namespace std;
#define M 100
#define N 100
#define MaxSize 100

struct Try //定义一个栈，保存路径
{
    int curX;            //当前方块的行号
    int curY;            //当前方块的列号
    int dir;             //dir是下一可走方位的方位号
} path[MaxSize];         //定义栈

int top = -1;            //初始化栈指针

int maze[100][100]={
        {1, 1, 1, 1, 1, 1, 1,},
        {1, 0, 1, 0, 0, 0, 1,},
        {1, 0, 1, 0, 1, 1, 1,},
        {1, 0, 0, 0, 1, 0, 1,},
        {1, 0, 1, 0, 0, 0, 1,},
        {1, 0, 1, 0, 1, 0, 1,},
        {1, 1, 1, 1, 1, 1, 1,},
};

void display(int row, int col); //输出迷宫地图