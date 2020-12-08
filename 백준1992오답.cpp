#include<iostream>

using namespace std;

int arr[100][100], n;

bool f(int x, int y, int size) {
    int all = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (all != arr[i][j])
                return false;
        }
    }
    return true;
}
void f_1(int x, int y, int size) {
    if (f(x, y, size)) {
        cout << arr[x][y];
    }
    else {
        cout << '(';
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                f_1(x + (i*(size/2)), y + (j*(size/2)), size/2);
            }
        }
        cout << ')';
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           cin >> arr[i][j];
        }
    }
    return 0;
}