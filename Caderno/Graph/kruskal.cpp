/*
	Kruskal Algorithm
	Minimum Spanning Tree

	Complexity: O(E lg(V))
*/

#include <algorithm>
#include "union_find.cpp"
using namespace std;

#define NODES 100

struct Edge {
	int u, v;
	int weight;

	bool operator < (const Edge& another) const {
		return weight < another.weight;
	}
};


vector<Edge> kruskal(vector<Edge> edges, int numOfNodes) {
	vector<Edge> mst;

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= numOfNodes; i++)
		unionFind[i] = i;

	for (Edge e : edges) {
		if (find(e.u) != find(e.v)) {
			mst.push_back(e);
			union(unionFind, e.u, e.v);
		}
	}

	return mst;
}