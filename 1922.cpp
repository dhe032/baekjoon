#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//함수선언
void init(void);
int kruskal(void);
void print(int cost);

int N, M;
int* searched_node;
struct edge {
	int cost;
	int node[2];
};

class compare {
public:
	bool operator() (edge& a, edge& b) {
		return a.cost > b.cost;
	}
};

priority_queue<edge, vector<edge>, compare> q; //compare라는 functor

class Tree {
private:
	vector<int> nodes;
	vector<edge> edges;
public:
	bool same_tree(int a, int b) {
	}
};


int main(void) {
	//함수의 호출로 이루어짐 == 함수형 프로그래밍
	init();
	print(kruskal());
}

//함수정의
void init(void) {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int src, dst, cst;
		cin >> src >> dst >> cst;
		q.push(edge({ cst, {src, dst} }));
		cout << "Pushed!" << endl;
	}
	searched_node = new int[N + 1];
	cout << "debug 0" << endl;
}

int kruskal(void) {
	int cnt = 0;
	int cost = 0;
	while (cnt != N) {
		cout << "debug 1" << endl;
		edge top = q.top();
		cout << "debug 2" << endl;
		q.pop();
		cout << "debug 3" << endl;
		(top.node[0],top.node[1])
		
		cout << "debug 4" << endl;
	}
	return cost;
}

void print(int cost) {
	cout << cost;
}
