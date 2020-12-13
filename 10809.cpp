#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#define INT_MAX 2100000000
using namespace std;

int alphabet[26];

enum {
	a = 0,
	b = 1
};

int main(void) {
	string S;
	cin >> S;
	memset(alphabet, -1, sizeof(int) * 26);

	for (int i = 0; i < S.length(); ++i){
		if (alphabet[S[i] - 'a'] == -1) {
			alphabet[S[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; ++i) {
		cout << alphabet[i] << " ";
	}
	return 0;
}