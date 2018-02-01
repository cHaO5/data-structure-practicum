#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

ifstream openFile;

void split(const string &s, vector<string> &v, char c);
void count();
void query();
void create(string fileName);