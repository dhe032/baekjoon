#include<iostream>
#include<string>

using namespace std;

int arr[100][100], n;

bool f(int x_i, int y_i, int x_e, int y_e) {
    int all = arr[x_i][y_i];
    for (int i = x_i; i <= x_e; i++) {
        for (int j = y_i; j <= y_e; j++) {
            if (all != arr[i][j])
                return false;
        }
    }
    return true;
}

void f_1(int x_i, int y_i, int x_e, int y_e) {
	if (x_i == x_e && y_i == y_e) {
		cout << arr[x_i][y_i];
	}
	else if (f(x_i, y_i, x_e, y_e)) {
        cout << arr[x_i][y_i];
    }
    else {
        cout << '(';
		f_1(x_i, y_i, (x_i + x_e) / 2, (y_i + y_e) / 2);
		f_1(x_i, (y_i + y_e) / 2 + 1, (x_i + x_e) / 2, y_e);
		f_1((x_i + x_e) / 2 + 1, y_i, x_e, (y_i + y_e) / 2);
		f_1((x_i + x_e) / 2 + 1, (y_i + y_e) / 2 + 1, x_e, y_e);
        cout << ')';
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
		string inp;
		cin >> inp;
        for (int j = 0; j < n; j++) {
           arr[i][j] = inp[j] - '0';
        }
    }
	f_1(0, 0, n - 1, n - 1);

    return 0;
}