#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 700
vector<int> graph[MAX];
bool visited[MAX];
int weight[MAX][MAX];

class MinPQ {
	public:
		pair<int, int> popMin();
		void insert(int a, int b);
		bool empty();
		void print();

	private:
		vector<pair<int, int> > v;
};

bool MinPQ::empty() {
	return this->v.size() == 0;
}

pair<int, int> MinPQ::popMin() {
	pair<int, int> p = this->v[0];
	this->v.erase(v.begin());
	return p;
}

static bool compare(const pair<int, int> a, const pair<int, int> b) {
	return weight[a.first][a.second] < weight[b.first][b.second];
}

void MinPQ::insert(int a, int b) {
	this->v.insert(std::lower_bound(this->v.begin(), this->v.end(), make_pair(a, b), compare), make_pair(a, b));
}

void MinPQ::print() {
	vector<pair<int, int> >::iterator it;
	printf("MinPQ vector:\n");
	for (it = this->v.begin(); it != this->v.end(); it++)
		printf("  %d-%d  %d\n", it->first, it->second, weight[it->first][it->second]);

	printf("\n\n");
}

void visit(MinPQ *pq, int x) {
	if (visited[x] == false) {
		visited[x] = true;
		vector<int>::iterator it;

		for (it = graph[x].begin(); it != graph[x].end(); it++) {
			if (visited[*it] == false)
				pq->insert(*it, x);
		}
	}
}

int mst() {
	MinPQ *pq = new MinPQ();
	vector<pair<int, int> > mst;

	visit(pq, 1);
	
	while(!pq->empty()) {
		pair<int, int> e = pq->popMin();
		int v = e.first, w = e.second;
		if (visited[v] && visited[w]) continue;
		mst.push_back(e);
		if (!visited[v]) visit(pq, v);
		if (!visited[w]) visit(pq, w); 
	}

	int res = 0;
	vector<pair<int, int> >::iterator it;
	for (it = mst.begin(); it != mst.end(); it++) {
		res += weight[it->first][it->second];
	}

	return res;
}



int main() {
	int n, m;
	int a, b, c;

	scanf("%d %d", &n, &m);

	while(m--) {
		scanf("%d %d %d", &a, &b, &c);
		weight[a][b] = weight[b][a] = c;
		visited[a] = visited[b] = false;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	printf("%d\n", mst());

	return 0;
}


