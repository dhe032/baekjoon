#include<iostream>

using namespace std;

int N, K;
int cnt = 0;
int* coin;

int main(void) {
	cin >> N >> K;
	coin = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> coin[i];

	for (int i = N - 1; i >= 0; --i) {
		while (K >= coin[i]) {
			K -= coin[i];
			++cnt;
		}
	}
	cout << cnt;
	delete[] coin;
}