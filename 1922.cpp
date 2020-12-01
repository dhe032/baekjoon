#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//함수선언
void init(void);
int kruskal(void);
void print(int cost);
int Find(int node);
void Union(int node_1, int node_2);

int N, M;
int* parent_node;
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
		//cout << "Pushed!" << endl;
	}
	parent_node = new int[N + 1];
	for (int i = 1; i <= N; ++i){ 
		parent_node[i] = i;
	}
	//cout << "debug 0" << endl;
}

int kruskal(void) {
	int cost = 0;
	while(!q.empty()){
		edge top = q.top();
		q.pop();
		if (Find(top.node[0]) != Find(top.node[1])) {
			//union keyword 공용체
			Union(top.node[0], top.node[1]);
			cost += top.cost;
		}
	}

	return cost;
}

void print(int cost) {
	cout << cost << endl;
}

// node의 root 노드 리턴, tree의 구조 변경
int Find(int node) { 
	if (parent_node[node] == node) return node;
	else return parent_node[node] = Find(parent_node[node]);
}

// 서로 다른 두개의 트리를 합친다 (합집합)
void Union(int node_1, int node_2) {
	parent_node[Find(node_2)] = node_1;
}