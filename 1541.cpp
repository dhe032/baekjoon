#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string str;
	int num[50];
	char op[50];
	int cnt = 0;
	int idx_n = 0, idx_o = 0;
	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if ('0' <= str[i] && str[i] <= '9')
			cnt++;
		else {
			num[idx_n++] = stoi(str.substr(i - cnt, cnt));
			op[idx_o++] = str[i];
			cnt = 0;
		}
	}
	num[idx_n++] = stoi(str.substr(str.length() - cnt, cnt));

	int answer = 0;
	int tmp = 0;
	cnt = 0;
	//bool flag = true;
	for (int i = 0; i < idx_o; ++i) {
		if (op[i] == '-' && cnt == 0) {
			tmp += num[i];
			answer += tmp;
			tmp = 0;
			cnt++;
		}
		else if(op[i] == '-') {
			tmp += num[i];
			answer -= tmp;
			tmp = 0;
		}
		else if (op[i] == '+') {
			tmp += num[i];
		}
		//cout << tmp << " " << answer << endl;
	}

	tmp += num[idx_n - 1];
	if (cnt == 0) {
		answer += tmp;
	}
	else {
		answer -= tmp;
	}

	cout << answer;

	return 0;
}