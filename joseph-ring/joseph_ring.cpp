//约瑟夫生死者游戏
//输入参与游戏的总人数，游戏开始位置，死亡数字，生者人数
//输出离开的旅客序号和剩余旅客序号
#include "joseph_ring.h"

int main() {
    cout << "现有N人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一人开始报数，如此循环，直至剩下K人为止" << endl;
    int N = 0, S = 0, M = 0, K = 0;
    cout << "请输入生死游戏的总人数N：";
    cin >> N;
    cout << "请输入游戏开始的位置S：";
    cin >> S;
    cout << "请输入死亡数字M：";
    cin >> M;
    cout << "请输入剩余的生者人数K：";
    cin >> K;
    check(N, S, M, K);
    Josephus newGame(N, S, M, K);
    newGame.startGame();
    return 0;
}

void Josephus::create() {
    int number = 1;
    Passenger *pre = NULL;
    for (int i = 0; i < n; ++i) {
        Passenger *p = new Passenger;
        p->index = number++;
        if (i == 0) {
            head = p;
        } else if (i == n - 1) {
            pre->next = p;
            p->next = head;
        } else {
            pre->next = p;
        }
        pre = p;
    }
}

void Josephus::startGame() {
    Passenger *p = head, *pre = NULL;
    while (p->index != s) p = p->next;
    int i = 1, count = 1;
    if (k == n) {
        cout << "无人死亡" << endl;
        return;
    }
    while (i <= m) {
        if (i < m) {
            pre = p;
            p = p->next;
            i++;
        } else {
            pre->next = p->next;
            cout << "第" << count << "个死者的位置是："
                 << std::right << setw(count > 9 ? 5 : 6)
                 << p->index << endl;
            if (p == head) head = p->next;
            delete p;
            count++;
            if (--left == k) break;
            i = 1;
            p = pre->next;
        }
    }
    cout << "最后剩下：" << k << "人" << endl;
    cout << "剩余的生者位置为：";
    if (k) {
        p = head;
        while (p->next != head) {
            cout << "     " << p->index;
            p = p->next;
        }
        cout << "     " << p->index;
    }
}

void check(int &n, int &s, int &m, int &k) {
    while (n < 0) {
        cout << "N值有误，请重新输入：";
        cin >> n;
        check(n, s, m, k);
    }
    while (s < 0) {
        cout << "S值有误，请重新输入：";
        cin >> s;
        check(n, s, m, k);
    }
    while (m < 0) {
        cout << "M值有误，请重新输入：";
        cin >> m;
        check(n, s, m, k);
    }
    while (k < 0) {
        cout << "K值有误，请重新输入：";
        cin >> k;
        check(n, s, m, k);
    }
    while (n < s) {
        cout << "N、S值有误，请分别重新输入N和S：";
        cin >> n >> s;
        check(n, s, m, k);
    }
    while (n < k) {
        cout << "N、K值有误，请分别重新输入N和K：";
        cin >> n >> k;
        check(n, s, m, k);
    }
    return;
}

Josephus::~Josephus() {
    Passenger *p = head;
    while (p->next != head) {
        Passenger *t = p->next;
        delete p;
        p = t;
    }
}