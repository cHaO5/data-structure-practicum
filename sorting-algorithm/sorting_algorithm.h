#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX = 10000;

void set(int a[], int size);
void bubbleSort(int a[]); //冒泡排序
void simpleSelectSort(int a[]);//简单选择排序
void insertSort(int a[]); //直接插入排序
void shellSort(int a[]);//希尔排序
int partition(int a[], int first, int end);
void quickSort(int a[], int first, int end); //快速排序
void sift(int a[], int k, int m);
void heapSort(int a[]); //堆排序
void merge(int a[], int first, int mid, int last, int temp[]);
void mergeSortN(int a[], int first, int last, int temp[]);
bool mergeSort(int a[]); //归并排序
int getNumInPos(int num, int pos);
void radixSort(int* pDataArray); //基数排序