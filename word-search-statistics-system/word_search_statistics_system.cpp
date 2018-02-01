//单词检索系统
//建立文本文件，根据文本文件统计单词数量，或检索单词出现的行数与列数
#include "word_search_statistics_system.h"

int main(void) {
    cout << "**         单词检索统计系统       **" << endl;
    cout << "==================================" << endl;
    cout << "**      请选择要执行的操作：       **" << endl;
    cout << "**         1.新建文件            **" << endl;
    cout << "**         2.单词计数            **" << endl;
    cout << "**         3.单词检索            **" << endl;
    cout << "**         4.退出程序            **" << endl;
    cout << "==================================" << endl;

    while (1) {
        cout << "\n请输入要执行的操作：";
        int ops;
        cin >> ops;
        switch (ops) {
            case 1: { //新建文件
                cout << "请输入要新建的文件名：";
                string fileName;
                cin >> fileName;
                create(fileName);
                break;
            }
            case 2: { //单词计数
                cout << "请输入要打开的文件名：";
                string fileName;
                cin >> fileName;
                openFile.open(fileName);
                if (openFile.is_open()) {         //判断文件是否正常打开
                    count();                      //统计单词
                    openFile.close();
                } else {
                    cout << "找不到这个文件！" << endl;
                }
                break;
            }
            case 3: { //单词检索
                cout << "请输入要打开的文件名：";
                string fileName;
                cin >> fileName;
                openFile.open(fileName);
                if (openFile.is_open()) {         //判断文件是否正常打开
                    query();                      //检索单词
                    openFile.close();
                } else {
                    cout << "找不到这个文件！" << endl;
                }
                break;
            }
            case 4: { //退出程序
                exit(0);
            }
            default:
                cout << "请输入正确的操作！" << endl;
                break;
        }
    }
}

void create(string fileName) {
    cout << "输入#结束" << endl;
    ofstream fout(fileName);
    while (1) {
        cout << "请逐行输入文本：";
        char t = getchar();
        if (t == '#') break;  //输入终止条件
        string line;
        getline(cin, line);
        fout << line+'\n';
    }
    fout.close();
}

void count() {
    cout << "请输入要检索的单词：";
    string word;
    cin >> word;

    string line;                  //每次读入一行句子
    int wordCount = 0, iCount = 0;            //所有单词量
    while (getline(openFile, line)) {
        vector<string> wordTable;
        split(line, wordTable, ' ');
        wordCount += wordTable.size();
        for (auto i:wordTable) {
            if (i[i.size() - 1] == '.' || i[i.size() - 1] == ',') { //去除末尾','和'.'
                i.erase(i.end() - 1);
            }
            if (i == word) {
                iCount++;
            }
        }
    }

    cout << "单词 " << word << " 出现了" << iCount << "次" << endl;
}

void split(const string &s, vector<string> &wordTable, char temp) {  //分词
    int first, second = 0;
    first = s.find(temp);
    while (string::npos != first) {
        wordTable.push_back(s.substr(second, first - second));
        second = first + 1;
        first = s.find(temp, second);
    }
    if (second != s.length()) { //找到单词
        wordTable.push_back(s.substr(second));
    }
}

void query() {
    cout << "请输入要检索的单词：";
    string word;
    cin >> word;
    string line;
    int iCount = 1, lineNum = 1, pos = 0;
    while (getline(openFile, line)) {      //逐行检索
        while ((pos = line.find(word, pos)) != string::npos
               && (line[pos + word.size()] == ' ' || line[pos + word.size()] == '\n'
                   || line[pos + word.size()]=='.' || line[pos + word.size()]==',')) {
            cout << "单词 " << word << " 第" << iCount++ << "次出现在第"
                 << lineNum << "行第" << pos << "列。" << endl;
            pos += word.size();
        }
        lineNum++;
        pos = 0;
    }
    cout << "单词 " << word << " 总共出现" << --iCount << "次。" << endl;
}