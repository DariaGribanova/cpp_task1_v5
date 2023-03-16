
#include <iostream>
using namespace std;
void enterArr(int** arr, int& n, int& m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}
void printArr(int** arr, int& n, int& m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int** swapLines(int** arr, int& n, int& m) {

    int max = arr[0][0];
    int min = arr[0][0];
    int maxI = 0;
    int minI = 0;



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                maxI = i;
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
                minI = i;
            }
        }
    }
    for (int j = 0; j < m; ++j)
    {
        int tempCell = arr[maxI][j];
        arr[maxI][j] = arr[minI][j];
        arr[minI][j] = tempCell;
    }
    return arr;
}

int main()
{
    setlocale(0, "");
    int* n = new int; //строки
    cin >> *n;
    int** arr = new int* [*n];
    int* m = new int; //столбцы
    cin >> *m;
    cout << endl;
    for (int i = 0; i < *n; i++) {
        arr[i] = new int[*m];
    }
    enterArr(arr, *n, *m);
    cout << endl;
    printArr(arr, *n, *m);
    cout << endl;
    int** arr2 = swapLines(arr, *n, *m);
    printArr(arr2, *n, *m);
    for (int i = 0; i < *n; i++) {
        delete[] arr[i];
    }
    delete n, m;
    system("pause");
    return 0;
}