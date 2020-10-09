#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;
	queue<int> q;
	cin >> a;
	cin >> b;
	cout << "<";
	for (int i=1; i<=a; i++) {
		q.push(i);
	}
	while ( !q.empty() ) {
		for (int j= 0; j<b-1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if ( !q.empty() )
			cout << ", ";
	}
	cout << ">";
}
