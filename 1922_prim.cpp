#include<iostream>
#include<queue>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

//�Լ�����
void init(void);
int prim(void);
void print(int cost);
int Find(int node);
void Union(int node_1, int node_2);

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

priority_queue<edge, vector<edge>, compare> q; //compare��� functor 
priority_queue<edge, vector<edge>, compare> child; //compare��� functor 
int* parent_node;
int N, M;
vector<list<pair<int, int>>> graph; // <node, cost>
edge initial;

int main(void) {
	//�Լ��� ȣ��� �̷���� == �Լ��� ���α׷���
	init();
	print(prim());
}

//�Լ�����
void init(void) {
	cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		int src, dst, cst;
		cin >> src >> dst >> cst;
		if (i == 0) initial = { cst, {src, dst} };
		else if (initial.cost > cst) initial = { cst, {src, dst} };
		graph[src].emplace_back(dst, cst);
		graph[dst].emplace_back(src, cst);
		//cout << "Pushed!" << endl;
	}
	parent_node = new int[N + 1];
	for (int i = 1; i <= N; ++i) {
		parent_node[i] = i;
	}
	
	q.push(initial);
}

int prim(void) {
	int cost = 0;
	while (!q.empty()) {

		cout << "debug 0" << endl;
		edge top = q.top();
		Union(top.node[0], top.node[1]);
		q.pop();
		cost += top.cost;
		
		list<pair<int, int>>::iterator iter = graph[top.node[0]].begin();
		list<pair<int, int>>::iterator min = iter;
		while (iter != graph[top.node[0]].end()) {
			cout << "debug 1" << endl;
			child.push(edge({ iter->second, {top.node[0], iter->first} })); // cost node0 node1
			/*
			pair<int, int> elem = *iter; // <node, cost>
			if (Find(elem.first) != Find(top.node[0])) {
				q.push(edge({ elem.second, {top.node[0], elem.first} }));
			}
			*/
			++iter;

		}

		iter = graph[top.node[1]].begin();
		while (iter != graph[top.node[1]].end()) {
			cout << "debug 2" << endl;
			child.push(edge({ iter->second, {top.node[1], iter->first} })); // cost node0 node1
			/*
			pair<int, int> elem = *iter; // <node, cost>
			if (Find(elem.first) != Find(top.node[1])) {
				q.push(edge({ elem.second, {top.node[1], elem.first} }));
			}
			*/
			++iter;
		}
		pair<int, int> elem = *min;
		while (!child.empty()) {
			edge top = child.top();
			child.pop();
			if (Find(top.node[0]) != Find(top.node[1])) {
				q.push(top);
				Union(top.node[0], top.node[1]);
				cost += top.cost;
				break;
			}
		}
		
	}
	return cost;
}

void print(int cost) {
	cout << cost << endl;
}

// node�� root ��� ����, tree�� ���� ����
int Find(int node) {
	cout << "debug 3 : " << node << " " << parent_node[node] << endl;

	if (parent_node[node] == node) return node;
	else return parent_node[node] = Find(parent_node[node]);
}

// ���� �ٸ� �ΰ��� Ʈ���� ��ģ�� (������)
void Union(int node_1, int node_2) {
	parent_node[Find(node_2)] = node_1;
}