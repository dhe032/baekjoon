#include<iostream>
#include<vector>

using namespace std;

int N, B;

vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B); // �Լ�����
vector<vector<int>> D(vector<vector<int>> A, int N); // �Լ�����
vector<vector<int>> matrix;

int main(void) {
	cin >> N >> B;
	// todo
	// 1. ��� �Է¹ޱ�
	// 2. D �Լ� ȣ��
	// 3. D ���ϰ� ���
}


vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> ret(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				ret[j][k] += A[i][j] * B[j][k];
			}
		}
	}
	return ret;
}
vector<vector<int>> D(vector<vector<int>> A, int N) {
	vector<vector<int>> ret(N, vector<int>(N, 0));
	if (N == 1) {
		ret = A;
	}
	else if (N % 2 == 0) {
		ret = mul(D(A, N / 2), D(A, N / 2)); // O(N) -> O(logN)
	}
	else {
		ret = mul(D(A, N - 1), D(A, 1));
	}
	return ret;
}