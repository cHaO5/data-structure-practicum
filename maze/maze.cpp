//勇闯迷宫游戏
//输入自定义迷宫地图或使用默认地图
//输出从起点到终点的路径
#include "maze.h"

int main() {
    int row, col;                                    //行数和列数
    cout << "请设置迷宫的行数和列数（任一为0则使用默认地图）：";
    cin >> row >> col;
    if (row != 0  && col != 0) {
        cout << "请设置" << row << '*' << col << "迷宫(1为墙壁，0为通道）：\n";
        for (int i = 0; i < row; i++) {              //输入迷宫数据
            for (int j = 0; j < col; j++) {
                cin >> maze[i][j];
            }
        }
        display(row, col);
    } else {
        display(7, 7);
    }


    int xBegin, yBegin, xExit, yExit;
    cout << "输入起点(分别输入横纵坐标）：";
    cin >> xBegin >> yBegin;
    cout << "输入出口(分别输入横纵坐标）：";
    cin >> xExit >> yExit;

    int curX, curY, dir, find, k;
    top++;                                          //初始方块进栈
    path[top].curX = xBegin;
    path[top].curY = yBegin;
    path[top].dir = -1;
    maze[xBegin][yBegin] = -1;
    while (top > -1)  {                             //栈不为空时循环
        curX = path[top].curX;
        curY = path[top].curY;
        dir = path[top].dir;
        if (curX == xExit && curY == yExit) {       //找到了出口，输出路径
            cout << "迷宫路径如下：\n";
            for (k = 0; k <= top; k++) {
                cout << "(" << path[k].curX << "," << path[k].curY << ")";
                if (k != top) cout << "-->";
            }
            cout << endl;
            return 0;
        }
        find = 0;
        while (dir < 4 && find == 0) {              //找下一个可走的点
            dir++;
            switch (dir) {
                case 0:  //向上
                    curX = path[top].curX - 1;
                    curY = path[top].curY;
                    break;
                case 1: //向右
                    curX = path[top].curX;
                    curY = path[top].curY + 1;
                    break;
                case 2:  //向下
                    curX = path[top].curX + 1;
                    curY = path[top].curY;
                    break;
                case 3:  //向左
                    curX = path[top].curX;
                    curY = path[top].curY - 1;
                    break;
            }
            if (maze[curX][curY] == 0) find = 1;     //找到通路
        }
        if (find == 1) {                             //找到了下一个可走方块
            path[top].dir = dir;                     //修改原栈顶元素的d值
            top++;                                   //下一个可走方块进栈
            path[top].curX = curX;
            path[top].curY = curY;
            path[top].dir = -1;
            maze[curX][curY] = -1;                   //避免重复走到这个方块
        } else {                                     //没有路可走，则退栈
            maze[path[top].curX][path[top].curY] = 0;//让该位置变成其它路径可走方块
            top--;
        }
    }
    cout << "没有可走路径！\n";
    system("pause");
    return 0;
}

void display(int row, int col) {
    cout << "迷宫地图：" << endl << "\t\t";           //展示迷宫地图
    for (int i = 0; i < row; i++) {
        cout << "第" << i << "列" << '\t';
    }
    cout << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == 0) {
                cout << "第" << i << "行" << '\t' << '\t';
            }
            cout << ((maze[i][j] == 0) ? 'x' : '#') << '\t' << '\t';
            if (j == col - 1) cout << endl;
        }
    }
}