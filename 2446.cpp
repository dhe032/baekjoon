#include<iostream>

using namespace std;

void star(int n);
void blank(int n);

int main(void) {
	int n, flag = 0;
	cin >> n;
	for (int i = 1, j = 1; i <= 2 * n - 1; ++i) {
		if (i == n) flag = 1;
		blank(j-1);
		star(2 * n - 1 - 2 * (j - 1));
		blank(j-1);
		if (flag == 0) j++;
		else j--;
		cout << endl;
	}
	return 0;
}


void star(int n) {
	for (int i = 0; i < n; ++i)
		cout << "*";
}
void blank(int n) {
	for (int i = 0; i < n; ++i)
		cout << " ";
}