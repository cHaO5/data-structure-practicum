#include <iostream>
#include <string>

using namespace std;

struct Edge {
    int num;     //次顶点序号
    float cost;  //边的开销
    Edge *next;  //指向下一个邻接顶点

};

class Node {
public:
    int start;   //头结点序号
    int end;     //尾节点序号
    float cost;  //造价

    Node() {}    //构造函数
    Node(int start, int end, float cost) {

        this->start = start;
        this->end = end;
        this->cost = cost;

    }

    ~Node() {}   //析构函数
};


class MinCost {
public:
    Node MSTree[100];
    int size;    //当前的容量值
    MinCost() { size = 0; }

    void insert(Node *&node) {
        MSTree[size].start = node->start;
        MSTree[size].end = node->end;
        MSTree[size].cost = node->cost;
        ++size;
    }
};

struct Vertex {
    int num;     //顶点序号
    string city; //小区名
    Edge *first;
};

class Net {
public:
    int size;           //顶点个数
    Vertex *vertArray;  //邻接表顶点表
    MinCost MST;

    Net() { size = 0; }
    ~Net() {}
    void create();
    void add();
    int findVertArray(string city);
    bool prim();
    void operation();
    void printMST();
};