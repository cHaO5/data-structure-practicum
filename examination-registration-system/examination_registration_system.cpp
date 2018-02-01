//考试报名系统
//功能包括输入考生信息、输出考生信息、查询考生信息、
//添加考生信息、修改考生信息和删除考生信息
#include "examination_registration_system.h"

int main() {
    System stuList;

    int num;
    cout << "首先请建立考生信息系统！\n"
         << "请输入考生人数：";
    cin >> num;
    if (num == 0) return 0;
    cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
    stuList.add(num);
    stuList.display();
    cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)" << endl;
    int ops = -1; //将要进行的操作
    int stuNum; //考生位置
    while (ops) {
        cout << "请选择您要进行的操作：";
        cin >> ops;
        switch (ops) {
            case 0:                                      //取消操作，退出程序
                cout << "已退出";
                break;
            case 1:                                      //插入操作
                cout << "请输入你要插入的考生位置：";
                cin >> stuNum;
                stuList.insert(stuNum);
                stuList.display();
                break;
            case 2:                                      //删除操作
                cout << "请输入要删除的考生的考号：";
                cin >> stuNum;
                stuList.remove(stuNum);
                stuList.display();
                break;
            case 3:                                      //查找操作
                cout << "请输入要查找的考生的考号：";
                cin >> stuNum;
                stuList.find(stuNum);

                break;
            case 4:                                      //修改操作
                cout << "请输入你要修改的考生的考号：";
                cin >> stuNum;
                stuList.modify(stuNum);
                stuList.display();
                break;
            case 5:                                      //统计操作
                stuList.count();
                break;

            default:
                cout << "该操作不存在，请重新输入!" << endl;
                break;
        }
    }
    return 0;
}

istream &operator>>(istream &in, Examinee &u) {
    cin >> u.examNo >> u.name >> u.gender >> u.age >> u.examType;
    return in;
}

ostream &operator<<(ostream &out, Examinee &u) {
    cout << u.examNo << '\t'
         << u.name << '\t'
         << u.gender << '\t'
         << u.age << '\t'
         << u.examType
         << endl;
    return out;
}


System::System() //构造函数
{
    head = new Examinee;
}

void System::add(int num) {
    struct Examinee *newStu, *end;
    end = head;
    while (num != getLength()) {
        newStu = new struct Examinee;
        cin >> *newStu;
        if (newStu == NULL) {
            cerr << "存储分配错误！" << endl;
            exit(1);
        }
        end->next = newStu;
        end = newStu;
    }
    end->next = NULL;
}

Examinee *System::search(int stuNum) {
    Examinee *cur = head->next;
    while (cur != NULL) {
        if (cur->examNo == stuNum) break; //循链找考号为pos的结点
        else cur = cur->next;
    }
    return cur;
}

Examinee *System::locate(int stuNum) {
    if (stuNum < 0) return NULL;
    Examinee *cur = head;
    int count = 0;
    while (cur != NULL && count < stuNum) {
        cur = cur->next;
        count++;
    }
    return cur;
}

void System::find(int stuNum) {
    Examinee *cur = search(stuNum);
    if (cur == NULL) {                        //查找失败
        cout << "你查找的考生号不存在！" << endl;
    } else {                                  //查找成功
        cout << "考号\t" << "姓名\t" << "性别\t" << "年龄\t" << "报考类别\t" << endl;
        cout << *cur;
    }
}

bool System::remove(int stuNum) {
    Examinee *cur = search(stuNum);
    if (cur == NULL) {           //删除不成功
        cout << "你删除的考生号不存在！" << endl;
        return false;
    }
    cout << "你删除的考生信息是："; //删除成功
    cout << *cur;
    Examinee *temp = head;
    while (temp->next != cur) {
        temp = temp->next;
    }
    temp->next = cur->next;
    delete cur;
    return true;
}

bool System::insert(int stuNum) {
    Examinee *cur = locate(stuNum - 1);
    if (cur == NULL) {                    //插入不成功
        cout << "你插入的位置不正确！" << endl;
        return false;
    }
    cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
    struct Examinee *newStu = new struct Examinee;
    cin >> *newStu;
    if (newStu == NULL) {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    newStu->next = cur->next;
    cur->next = newStu;
    return true;                          //插入成功
}

void System::modify(int stuNum) {
    if (stuNum <= 0) {                          //考生号不符合要求
        cout << "输入的考生号不存在！" << endl;
        return;
    }
    Examinee *cur = search(stuNum);
    if (cur == NULL) {                          //所修改考生不在系统中
        cout << "输入的考生号不存在！" << endl;
        return;
    } else {
        cout << "请依次输入要修改的考生的考号，姓名，性别，年龄及报考类别！" << endl;
        cin >> *cur;
    }
}

void System::display() //打印整条链表
{
    cout << "考号\t" << "姓名\t" << "性别\t" << "年龄\t" << "报考类别\t" << endl;
    Examinee *cur = head->next;
    while (cur != NULL) {
        cout << *cur;
        cur = cur->next;
    }
}

int System::getLength() const {
    if (head->next == NULL) return 0;
    Examinee *u = head->next;
    int count = 0;
    while (u) {
        count++;
        if (u->next == NULL) break;
        u = u->next;
    }
    return count;
}

void System::count() {
    cout << "报名系统现有考生" << getLength() << "人。" << endl;   //系统中考生总人数
    cout << "请输入你要统计的考生报考类型：";                        //相应报考类型人数
    string type;
    cin >> type;
    int iCount = 0;
    Examinee *u = head->next;
    while (u) {
        if (type == u->examType) iCount++;
        u = u->next;
    }
    cout << "报考" << type << "类型的考生共有" << iCount << "人。" << endl;
}

System::~System() //析构函数
{
    Examinee *u;
    while (head->next != NULL) //当链不空时，删去链中所有结点
    {
        u = head->next;
        head->next = u->next; //保存被删结点，从链上摘下该结点
        delete u; //删除（仅保留一个表头结点）
    }
}