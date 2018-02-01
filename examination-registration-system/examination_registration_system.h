#include<iostream>
#include<string>

using namespace std;

struct Examinee {
    int examNo;             //考号
    string name;            //姓名
    string gender;          //性别
    float age;              //年龄
    string examType;        //报考类别
    struct Examinee *next;  //指针域
};

class System {
public:
    System();                      //Constructor
    void add(int num);             //添加元素到链表,默认到尾部添加
    Examinee *search(int stuNum);  //搜索考号为stuNum的元素
    Examinee *locate(int stuNum);  //搜索第stuNum个元素的地址
    void find(int stuNum);         //查找考号为stuNum的考生
    bool remove(int stuNum);       //删除第stuNum个位置的元素
    bool insert(int stuNum);       //在第stuNum个位置将信息插入到System
    void display();                //对System的元素进行显示
    void modify(int stuNum);       //更改第stuNum个位置的data
    int getLength() const;         //得到System的长度
    void count();                  //统计某类别考生人数
    ~System();                     //Destructor

private:
    struct Examinee *head;
};

istream &operator>>(istream &in, Examinee &u);

ostream &operator<<(ostream &out, Examinee &u);
