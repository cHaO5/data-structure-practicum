//家谱管理系统
//功能包括家谱成员信息的建立、查找、插入、修改与删除操作
#include"genealogy_system.h"

int main() {
    cout << "**         家谱管理系统          **" << endl;
    cout << "==================================" << endl;
    cout << "**      请选择要执行的操作：      **" << endl;
    cout << "**        A.完善家谱             **" << endl;
    cout << "**        B.添加家庭成员         **" << endl;
    cout << "**        C.解散局部家庭         **" << endl;
    cout << "**        D.更改家庭成员姓名      **" << endl;
    cout << "**        E.退出程序             **" << endl;
    cout << "==================================" << endl;


    cout << "首先建立一个家谱!" << endl;
    Tree family;
    family.create(family);
    char mark = ' ';
    while(mark != 'E') {
        cout << "\n请选择要执行的操作:";
        cin >> mark;
        switch(mark) {
            case'A': {  //完善家谱
                family.complete(family);
                break;
            }
            case'B': {  //添加家庭成员
                family.insert(family);
                break;
            }
            case'C': {  //解散局部家庭
                family.dismiss(family);
                break;
            }
            case'D': {  //更改家庭成员姓名
                family.update(family);
                break;
            }
            case'E':    //退出程序
                break;
            default:
                cout << "请输入正确操作!" << endl;
        }
    }
}

void Tree::create(Tree& L) { //建立一个家谱
    cout << "请输入祖先的名字:";
    string rootname;
    cin >> rootname;
    person* p = new person;
    p->name = rootname;
    L.root = p;              //添加为根节点
    cout << "此家谱的祖先:" << p->name << endl;
}

void Tree::complete(Tree& L) {
    cout << "请输入要创立家庭的人的姓名:";
    string rootname;
    cin >> rootname;
    person* s = Tree::search(L.root,rootname);
    if(s) {
        person* r = s;
        cout << "请输入" << s->name << "的儿女数:";
        int n;
        cin >> n;
        int m = n;
        cout << "请依次输入" << s->name << "的儿女的姓名:";
        while(m) {
            string na;
            cin >> na;
            person* p = new person;
            p->name = na;
            if(m == n) {
                s->firstChild = p;
                s = s->firstChild;
            } else {
                s->nextSibling = p;
                s = s->nextSibling;
            }
            m--;
        }
        Tree::print(r);
    } else {          //若要创立家庭的人不在家谱中
        cout << "查无此人，请重新输入!" << endl;
        Tree::complete(L);
    }
}

person* Tree::search(person* p,string name) {  //在家谱中检索成员
    person* t = NULL;
    person* s[100];  //辅助数组
    int top = 0;
    while(p || top > 0) {
        while(p) {
            if(p->name == name) {
                t = p;
            }
            s[++top] = p;
            p = p->firstChild;
        }
        p = s[top--];
        p = p->nextSibling;
    }
    return t;
}



void Tree::print(person* p) {
    cout << p->name << "的第一代子孙是:" << p->firstChild->name << "\t\t";
    p = p->firstChild;
    while(p->nextSibling) {
        cout << p->nextSibling->name << '\t';
        p = p->nextSibling;
    }
    cout << endl;
}

void Tree::insert(Tree& L) {
    cout << "请输入要添加子女的人的姓名:";
    string rootname;
    cin >> rootname;
    person* s = Tree::search(L.root,rootname);
    if(s) {  //添加新结点
        person* r = s;
        cout << "请输入" << s->name << "新添加的子女的姓名:";
        person* p = new person;
        string name;
        cin >> name;
        p->name = name;
        if(!s->firstChild) { //若当前节点无孩子节点
            s->firstChild = p;
        } else {
            s = s->firstChild;
            while(s->nextSibling) {
                s = s->nextSibling;
            }
            s->nextSibling = p;
        }
        Tree::print(r);
    } else {
        cout << "查无此人，请重新输入!" << endl;
        Tree::insert(L);
    }
}

void Tree::dismiss(Tree& L) {     //解散家庭
    cout << "请输入要解散家庭的人的姓名:";
    string rootname;
    cin >> rootname;

    person * subTree = search(L.root, rootname);
    if(subTree) {
        cout << "要解散家庭的人是：" << rootname << endl;
        Tree::print(subTree);
        L.kill(L.search(L.root, rootname));
    } else {
        cout << "查无此人，请重新输入!" << endl;
        Tree::dismiss(L);
    }

}

void Tree::kill(person *subTree)  //删除结点
{
    if(subTree) {                 //当前指针不为空 说明有子树
        kill(subTree->firstChild);//则递归下去
        delete subTree;           //最后删除
    }
}

void Tree::update(Tree& L)
{
    cout << "请输入要更改姓名的人的目前姓名:";
    string rootname;
    cin >> rootname;
    person* s = Tree::search(L.root,rootname);
    if(s) {
        cout << "请输入更改后的名字:";
        string name;
        cin >> name;
        s->name = name;
        cout << rootname << "已更改为" << s->name << endl;
    } else {  //若要求更改的成员不在家谱中，重新输入
        cout << "查无此人，请重新操作!" << endl;
        Tree::update(L);
    }
}