#include <iostream>
#include <iomanip>

using namespace std;

struct Passenger {
    int index;
    Passenger *next;
};

class Josephus {
private:
    Passenger *head;
    int left;   //剩余旅客数量
    int n, s, m, k;

public:
    Josephus(const int &N, const int &S, const int &M, const int &K): n(N), s(S), m(M), k(K), left(N) {
        create();
    }
    ~Josephus();
    void create();    //创建旅客列表
    void startGame(); //开始模拟游戏

};

void check(int &n, int &s, int &m, int &k);     //检查输入的数据