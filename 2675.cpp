#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int R;
		string S;
		cin >> R >> S;
		for (string::iterator iter = S.begin(); iter != S.end(); ++iter) {
			for (int i = 0; i < R; ++i) {
				cout << *iter;
			}
		}
		cout << endl;
	}
}