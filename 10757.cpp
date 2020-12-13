#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	string A, B, answer;
	answer = "";
	int length, carry = 0;
	cin >> A >> B;
	// A.length();
	// B.length();
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	if (A.length() < B.length()) {
		swap(A, B);
	}
	length = A.length();

	for (int i = 0; i < length; ++i) {
		if (i >= B.length()) {
			B += "0";
		}
		int sum = (A[i] -'0') + (B[i] - '0') + carry;
		answer += (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry != 0) {
		answer += carry + '0';
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
}