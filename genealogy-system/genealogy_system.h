#include<iostream>
#include<string>
using namespace std;

class person //定义节点类
{
    friend class Tree; //家族树类为友元
public:
    person() :name("?"), firstChild(NULL), nextSibling(NULL){};
private:
    string name;
    person* firstChild;
    person* nextSibling;
};

class Tree
{
public:
    Tree() :root(NULL){};   //构造函数
    void create(Tree& L);   //建立家庭
    void complete(Tree& L); //完善家庭
    void dismiss(Tree& L);  //解散家庭
    void kill(person* p);   //删除节点
    void insert(Tree& L);   //添加家庭成员
    void update(Tree& L);   //更改成员信息
    void print(person* p);  //输出第一代子孙
    person* search(person* p, string name); // 在家谱中搜索成员

    person* root;
};