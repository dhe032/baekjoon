#include<iostream>

using namespace std;

int main(void) {
	int N, next_number, cnt = 0;
	cin >> N;
	next_number = N;
	do {
		cnt++;
		int sum = next_number / 10 + next_number % 10;
		next_number = next_number % 10 * 10 + sum % 10;
	} while (N != next_number);
	cout << cnt;
}