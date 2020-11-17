// DP
// Greedy

#include<iostream>
#include<algorithm>

using namespace std;

int N;
int Q;
int R;
int cnt;

int arr[5001];

int DP(int N) {
	//cout << "debug " << N << endl;
	int ret;
	if (N <= 5) {
		if (N < 3) return -1;
		if (N == 3) return 1;
		if (N == 4) return -1;
		if (N == 5) return 1;
	}
	if (arr[N] != 0) {
		//cout << "ret : " << arr[N] << endl;
		return arr[N];
	}
	else {
		int a = DP(N - 3);
		int b = DP(N - 5);
		if (a != -1) {
			if (b != -1) ret = min(a, b) + 1; //Greedy algorithm
			else ret = a + 1;
		}
		else {
			if (b != -1) ret = b + 1;
			else ret = -1;
		}
	}
	//cout << "ret : " << ret << endl;
	return arr[N] = ret;
}

int main(void) {
	cin >> N;
	cout << DP(N) << endl;
	/*
	for (int i = 0; i <= N; ++i) {
		cout << i << " : " << arr[i] << endl;
	}
	*/
	return 0;
}