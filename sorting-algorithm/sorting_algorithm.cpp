//8种排序算法的比较案例
#include "sorting_algorithm.h"

int iCount = 0;
time_t before, after;
int size = 0;

int main() {
    int array[MAX];
    cout << "**                排序算法比较            **\n";
    cout << "===========================================\n";
    cout << "**             1 --- 冒泡排序             **\n";
    cout << "**             2 --- 选择排序             **\n";
    cout << "**             3 --- 直接插入排序         **\n";
    cout << "**             4 --- 希尔排序             **\n";
    cout << "**             5 --- 快速排序             **\n";
    cout << "**             6 --- 堆排序               **\n";
    cout << "**             7 --- 归并排序             **\n";
    cout << "**             8 --- 基数排序             **\n";
    cout << "**             9 --- 退出程序             **\n";
    cout << "===========================================\n\n";
    while (1) {
        cout << "请输入要产生的随机数个数:";
        cin >> size;
        if (size > 0 && size <= MAX) break;
        cout << "输入的数字大小在0~10000，请重新输入！" << endl;
    }

    while (1) {
        set(array, size);
        cout << "\n请选择排序算法:";
        char select;
        cin >> select;
        iCount = 0;
        switch (select) {
            case '1': {
                before = clock();
                bubbleSort(array);
                after = clock();
                cout << "冒泡排序算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '2': {
                before = clock();
                simpleSelectSort(array);
                after = clock();
                cout << "选择排序算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '3': {
                before = clock();
                insertSort(array);
                after = clock();
                cout << "选择直接插入算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '4': {
                before = clock();
                shellSort(array);
                after = clock();
                cout << "选择希尔算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '5': {
                before = clock();
                quickSort(array, 1, MAX);
                after = clock();
                cout << "快速排序算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '6': {
                before = clock();
                heapSort(array);
                after = clock();
                cout << "选择排序算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '7': {
                before = clock();
                mergeSort(array);
                after = clock();
                cout << "选择归并算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '8': {
                before = clock();
                radixSort(array);
                after = clock();
                cout << "选择基数算法排序所用时间为:\t" << difftime(after, before) / CLOCKS_PER_SEC << "秒\n";
                cout << "交换次数:" << iCount << endl;
                break;
            }
            case '9': {
                return 0;
            }
            default: {
                cout << "输入错误！" << endl;
                break;
            }

        }

    }
}

void set(int a[], int size) {
    for (int i = 0; i < size; i++)
        a[i] = rand();
}

void bubbleSort(int a[]) { //冒泡排序
    int exchange = size;
    int bound;
    while (exchange != 0) {
        bound = exchange;
        exchange = 0;
        for (int i = 1; i < size; i++) {
            if (a[i] > a[i + 1]) {  //如果前一个数大于后面的数，交换
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                exchange = i;
                iCount++;
            }
        }
    }
}

void simpleSelectSort(int a[]) { //简单选择排序

    for (int i = 1; i < size; i++) {
        int index = i;
        for (int j = i + 1; j <= size; j++) //在无序区中选择最小数
            if (a[j] < a[index])
                index = j;
        if (index != i) {
            int tmp = a[i];
            a[i] = a[index];
            a[index] = tmp;
            iCount++;
        }
    }
}

void insertSort(int a[]) { //直接插入排序
    int j;
    for (int i = 2; i <= size; i++) {
        a[0] = a[i];
        for (j = i - 1; a[0] < a[j]; j--) { //寻找未排序的数
            a[j + 1] = a[j];
            iCount++;
        }
        a[j + 1] = a[0];
    }
}

void shellSort(int a[]) { //希尔排序
    int d; //增量
    int i, j;
    for (d = size / 2; d >= 1; d = d / 2) {
        for (i = d + 1; i < size; i++) {
            a[0] = a[i];
            for (j = i - d; j > 0 && a[0] < a[j]; j = j - d) //后移
                a[j + d] = a[j];
            a[j + d] = a[0];
            iCount++;
        }
    }
}

//快速排序
int partition(int a[], int first, int end) {//快速排序一次划分
    int i = first, j = end;
    while (i < j) {
        while (i < j && a[i] <= a[j]) { //右侧扫描
            j--;
        }
        if (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            iCount++;
        }

        while (i < j && a[i] <= a[j]) { //左侧扫描
            i++;
        }
        if (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            j--;
            iCount++;
        }
    }
    return i; //返回轴值
}

void quickSort(int a[], int first, int end) { //快速排序
    if (first < end) {
        int pivot = partition(a, first, end); //分区 和返回轴值
        quickSort(a, first, pivot - 1); //左侧快速排序
        quickSort(a, pivot + 1, end); //右侧快速排序
        iCount++;
    }
}

//堆排序
void sift(int a[], int k, int m) { //筛选法调整堆
    int i = k, j = 2 * k; //j指向左孩子
    while (j <= m) {
        if (j < m && a[j] < a[j + 1]) {
            j++;
        }
        if (a[i] > a[j])
            break;
        else {
            int tmp = a[i];
            a[i] = a[j];

            a[j] = tmp;

            i = j;
            j = 2 * i;
            iCount++;
        }
    }
}

void heapSort(int a[]) { //堆排序
    for (int i = size / 2; i >= 1; i--)
        sift(a, i, size);
    for (int i = 1; i < size; i++) //移去对顶并重建大根堆
    {
        int tmp = a[1];
        a[1] = a[size - i + 1];
        a[size - i + 1] = tmp;
        sift(a, 1, size - i);
        iCount++;
    }
}

//归并排序
void merge(int a[], int first, int mid, int last, int temp[]) {//将有二个有序数列合并
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
        iCount++;
    }

    while (i <= m) {
        temp[k++] = a[i++];
        iCount++;
    }
    while (j <= n) {
        temp[k++] = a[j++];
        iCount++;
    }

    for (i = 0; i < k; i++) {
        a[first + i] = temp[i];
        iCount++;
    }
}

void mergeSortN(int a[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSortN(a, first, mid, temp);    //左边有序
        mergeSortN(a, mid + 1, last, temp); //右边有序
        merge(a, first, mid, last, temp); //再将二个有序数列合并
        iCount++;
    }
}

bool mergeSort(int a[]) {
    int *p = new int[size];
    if (p == NULL) return false;
    mergeSortN(a, 0, size - 1, p);
    iCount++;
    delete[] p;
    return true;
}

//基数排序
int getNumInPos(int num, int pos) { // 找到num的从低到高的第pos位的数据
    int temp = 1;
    for (int i = 0; i < pos - 1; i++) {
        temp *= 10;
    }
    return (num / temp) % 10;
}

void radixSort(int *pDataArray) {
    int *radixArrays[10];    //分别为0~9的序列空间
    for (int i = 0; i < 10; i++) {
        radixArrays[i] = (int *) malloc(sizeof(int) * (size + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= 10; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < size; i++)    //分配过程
        {
            int num = getNumInPos(pDataArray[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = pDataArray[i];
        }

        for (int i = 0, j = 0; i < 10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++) { pDataArray[j++] = radixArrays[i][k]; }
            radixArrays[i][0] = 0;    //复位
        }
    }
}