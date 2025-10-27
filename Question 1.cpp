#include <iostream>
using namespace std;

void ChangeLocation(char *Array, int b1, int b2) {
    if (b1 >= b2) return;
    char temp = Array[b1 - 1];
    Array[b1 - 1] = Array[b2 - 1];
    Array[b2 - 1] = temp;
    ChangeLocation(Array, b1 + 1, b2 - 1);
}

void PrintPattern(int n) {
    if (n == 0) return;
    for (int i = 0; i < n; i++) cout << n << " ";
    cout << endl;
    PrintPattern(n - 1);
}

int main() {
    char arr[8] = {'C','O','M','P','U','T','E','R'};
    ChangeLocation(arr, 3, 7);
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    cout << endl;
    int n = 4;
    PrintPattern(n);
    return 0;
}
