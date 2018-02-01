#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node, *Tree;

bool search(Tree T, int key);
Tree insert(Tree T, int key);
void remove(Tree T, int key);     //删除指定的节点
Tree create();         //创建二叉排序树
void show(Tree T);   //中序遍历并显示