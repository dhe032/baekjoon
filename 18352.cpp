#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, K, X;
vector<list<int>> city;
vector<int> min_distance;
queue<int> nodes;

void init() {
	cin >> N >> M >> K >> X;
	vector<list<int>> tmp1(N + 1);
	vector<int> tmp2(N + 1, INT_MAX);
	while (M--) {
		int src, dst;
		cin >> src >> dst;
		tmp1[src].push_back(dst);
	}
	city = tmp1;
	min_distance = tmp2;
	min_distance[X] = 0;
}

void dijkstra(void) {
	nodes.push(X);
	while (!nodes.empty()) {
		int front = nodes.front();
		nodes.pop();
		for (auto iter = city[front].begin(); iter != city[front].end(); iter++) {
			int tmp = min(min_distance[*iter], min_distance[front] + 1);
			if (min_distance[*iter] != tmp) {
				min_distance[*iter] = tmp;
				nodes.push(*iter);
			}
		}
	}
}

void print(void) {
	int flag = 0;
	for (int i = 1; i < min_distance.size(); ++i) {
		if (min_distance[i] == K) {
			cout << i << endl;
			flag++;
		}
	}
	if (flag == 0)
		cout << -1 << endl;
}

int main(void) {
	init();
	dijkstra();
	print();
	return 0;
}