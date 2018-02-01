//二叉排序树
//输入关键数建立二叉排序树，并实现二叉排序树的插入和查找功能
#include "binary_sorting_tree.h"

int main() {
    int choice, key;
    Tree T = NULL;
    cout << "**             二叉排序树            **" << endl;
    cout << "======================================" << endl;
    cout << "**        1 --- 建立二叉排序树        **" << endl;
    cout << "**        2 --- 插入元素             **" << endl;
    cout << "**        3 --- 查询元素             **" << endl;
    cout << "**        4 --- 退出程序             **" << endl;
    cout << "======================================" << endl;

    do {
        cout << "\nPlease select:\t";
        cin >> choice;
        switch (choice) {
            case 1:
                T = create();
                cout << "Bsort_Tree is:" << endl;
                show(T);
                cout << endl;
                break;
            case 2:
                cout << "Please input key which inserted:\t";
                cin >> key;
                T = insert(T, key);
                cout << "Bsort_Tree is:" << endl;
                show(T);
                cout << endl;
                break;
            case 3:
                cout << "Please input key which searched:\t";
                cin >> key;
                if (search(T, key)) {
                    cout << "Search success!" << endl;
                } else {
                    cout << key << " not exist!" << endl;
                }
                break;
            case 4:
                return 0;
            case 5:
                cout << "Please input key which removed:";
                cin >> key;
                remove(T, key);
            default:
                cout << "Wrong input!Please select again!" << endl;
                break;
        }
    } while (choice != 0);
    cout << "\n----------End--------" << "\n";
    return 0;
}

bool search(Tree T, int key) {  //搜索指定节点
    Tree p = T;
    while (p) {
        if (key == p->data) {
            return true;
        } else {
            p = (key < p->data) ? (p->lchild) : (p->rchild);
        }
    }
    return false;
}

Tree insert(Tree T, int key) {  //插入节点
    Tree p = T;
    Tree f = NULL, s;
    while (p != NULL) {
        f = p;
        if (key == p->data) {
            cout << "The input key<" << key << ">is have in！" << endl;
            return T;
        }
        p = (key > p->data) ? p->rchild : p->lchild;
    }
    s = new Node;
    s->data = key;
    s->lchild = NULL;
    s->rchild = NULL;
    if (T == NULL) return s;
    if (key < f->data) {
        f->lchild = s;
    } else {
        f->rchild = s;
    }
    return T;
}

void remove(Tree T, int key)      //删除指定的节点
{
    Tree p = T, q, f = NULL, s;
    while (p) {                   //先寻找到要删除的节点
        if (key == p->data) {
            break;
        }
        f = p;
        p = (key < p->data) ? p->lchild : p->rchild;
    }
    if (!p) {
        cout << "The key which removed is not exist!" << "\n";
    } else if (!p->lchild && !p->rchild) { //若当前节点没有孩子节点
        if (p == T) T = NULL;
        if (p == f->lchild) {
            f->lchild = NULL;
        } else {
            f->rchild = NULL;
        }
        delete p;
        p = NULL;
    } else if (!p->lchild && p->rchild) { //若当前节点只有右子节点
        if (f->lchild == p) {
            f->lchild = p->rchild;
        } else {
            f->rchild = p->rchild;
        }
        delete p;
        p = NULL;
    } else if (!p->rchild && p->lchild) { //若当前结点只有左子节点
        if (f->lchild == p) {
            f->lchild = p->lchild;
        } else {
            f->rchild = p->lchild;
        }
        delete p;
        p = NULL;
    } else {
        q = p;
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        p->data = s->data;
        if (q != p) {
            q->rchild = s->lchild;
        } else {
            q->lchild = s->lchild;
        }
        delete s;
        s = NULL;
    }
}

Tree create()         //创建二叉排序树
{
    int key;
    Tree T = NULL;
    cout << "Please input key to create Bsort_Tree:" << endl;
    cin >> key;
    while (key != 0) {
        T = insert(T, key);
        cin >> key;
    }
    return T;
}

void show(Tree T)     //中序遍历并显示
{
    if (T) {
        show(T->lchild);
        cout << T->data << "->";
        show(T->rchild);
    }
    return;
}