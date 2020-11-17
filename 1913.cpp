#include<iostream>
#include<vector>

using namespace std;

int N;

int greedy(vector<vector<int>> t) {
	int ret = 1;
	vector<int> current_state = t[0];
	for (int i = 0; i < N; ++i) {
		if (current_state[1] <= t[i][0]) {
			ret++;
			current_state = t[i];
		}
	}
	return ret;
}

int main(void) {
	cin >> N;
	vector<vector<int>> t(N,vector<int>(2,0));
	for (int i = 0; i < N; ++i) {
		cin >> t[i][0] >> t[i][1];
	}

	cout << greedy(t);

}