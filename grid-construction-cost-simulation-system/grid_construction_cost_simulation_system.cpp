//电网建设造价模拟系统
//根据输入建立小区之间的电网，生成最小生成树
#include "grid_construction_cost_simulation_system.h"

int main() {
    cout << "**             电网造价模拟系统            **" << endl;
    cout << "===========================================" << endl;
    cout << "**            A --- 创建电网顶点           **" << endl;
    cout << "**            B --- 添加电网的边           **" << endl;
    cout << "**            C --- 构造最小生成树         **" << endl;
    cout << "**            D --- 显示最小生成树         **" << endl;
    cout << "**            E --- 退出   程序           **" << endl;
    cout << "===========================================\n" << endl;
    Net power;
    power.operation();
    return 0;
}

void Net::create() {
    cout << "请输入顶点的数目:";
    cin >> size;
    cin.sync();  //清除多余的输入
    if (size >= 50) {
        cout << "超过最大容量！" << endl;
        return;
    }
    vertArray = new Vertex[size];

    cout << "请依次输入各顶点名称:" << endl;;
    for (int i = 0; i < size; ++i) {
        vertArray[i].num = i;  //顶点序号
        cin >> vertArray[i].city;  //输入顶点的值
        vertArray[i].first = NULL;
    }
    cin.sync();

}

void Net::add() {
    string temp;
    int index = 0;

    for (int i = 0; i < size * (size - 1) / 2; ++i) {
        cout << "请输入两个顶点及边：";
        cin >> temp;
        if (temp == "?") break;  //?表示停止输入
        index = findVertArray(temp);
        if (index == -1) {
            cout << "没有该初始顶点" << endl;
            continue;
        }

        Edge *temp1 = new Edge;
        cin >> temp;
        cin >> temp1->cost;
        temp1->num = findVertArray(temp);
        temp1->next = NULL;

        if ((vertArray[index].first) == NULL) {
            vertArray[index].first = temp1;
        } else {
            temp1->next = (vertArray[index].first)->next;
            vertArray[index].first->next = temp1;
        }

        Edge *temp2 = new Edge;
        temp2->num = vertArray[index].num;
        temp2->cost = temp1->cost;
        temp2->next = NULL;

        index = temp1->num;  //插入另一个点为起点的邻接表
        if ((vertArray[index].first) == NULL) {
            vertArray[index].first = temp2;
        } else {
            temp2->next = (vertArray[index].first)->next;
            vertArray[index].first->next = temp2;
        }
    }
    cout << "边导入完毕！" << endl;
}

int Net::findVertArray(string city) {
    for (int i = 0; i < size; ++i) {
        if (vertArray[i].city == city)
            return i;
    }
    return -1;
}

bool Net::prim() {

    Edge *edgeFirst;
    string temp;
    int near[50];
    int lowCost[50];
    int index = 0;
    int minIndex = 0;

    cout << "请输入起始顶点： ";
    cin >> temp;
    index = findVertArray(temp);
    if (index == -1) {
        cout << "没有该初始顶点" << endl;
        return false;
    }

    for (int i = 0; i < size; ++i)  //初始化near, lowCost
    {
        near[i] = -2;
        lowCost[i] = 9999;  //9999表示无穷大
    }

    minIndex = index;
    near[index] = -1;  //标记起始点

    bool createOver = false;
    while (!createOver) {
        for (int i = 0; i < size; ++i) {
            edgeFirst = vertArray[i].first;
            if (near[i] == -1) continue;
            while (edgeFirst != NULL) {
                if ((near[edgeFirst->num] == -1) && (edgeFirst->cost < lowCost[i])) {
                    near[i] = edgeFirst->num;
                    lowCost[i] = edgeFirst->cost;
                }
                edgeFirst = edgeFirst->next;
            }
        }

        for (int i = 0; i < size; ++i) {
            if ((lowCost[i] < lowCost[minIndex]) && (near[i] != -1)) {
                minIndex = i;
            }
        }

        if (lowCost[minIndex] < 9999 && near[minIndex] != -1) {
            Node *tmepNode = new Node(minIndex, near[minIndex], lowCost[minIndex]);
            MST.insert(tmepNode);
            near[minIndex] = -1;
            minIndex = index;  //index是起始顶点号
        }

        for (int i = 0; i < size; ++i) {
            if (near[i] != -1) break;
            if (i == size - 1) createOver = true;
        }

    }
    cout << "已生成Prim最小生成树!" << endl;
    return true;
}

void Net::operation() {
    char strOpe;
    while (true) {

        cout << "请选择操作: ";
        cin >> strOpe;
        cin.sync();//清除多余内容
        if (strOpe == 'A' || strOpe == 'a') {
            create();
        }
        if (strOpe == 'B' || strOpe == 'b') {
            add();
        }
        if (strOpe == 'C' || strOpe == 'c') {
            prim();
        }
        if (strOpe == 'D' || strOpe == 'd') {
            cout << "最小生成树的顶点及边为：" << endl;
            printMST();
        }
        if (strOpe == 'E' || strOpe == 'e') break;  //退出while(true)
        putchar(10);
    }
}

void Net::printMST() {
    for (int i = 0; i < MST.size; ++i) {
        cout << vertArray[MST.MSTree[i].start].city
             << "-<"
             << MST.MSTree[i].cost
             << ">" << "->"
             << vertArray[MST.MSTree[i].end].city
             << "\t";
    }
}