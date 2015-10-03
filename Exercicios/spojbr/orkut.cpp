#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define MAX 50

map<string, int> names;
map<int, string> names_rev;

typedef struct {
	bool error;
	vector<int> ns;
} Result;

void debug_printmapsi(map<string, int> mymap) {
	map<string, int>::iterator it;
	printf("\n\n===== ====== ===== =====\nPrinting map <string, int>:\n");
	
	for(it = mymap.begin(); it != mymap.end(); it++) {
		cout << "  -> " << it->first << " = " << it->second << endl;
	}
	printf("===== ===== ===== =====\n\n");
}

void debug_printmapis(map<int, string> mymap) {
	map<int, string>::iterator it;
	printf("\n\n===== ====== ===== =====\nPrinting map <int, string>:\n");
 		
	for(it = mymap.begin(); it != mymap.end(); it++) {
		cout << "  -> " << it->first << " = " << it->second << endl;
	}
	printf("===== ===== ===== =====\n\n");
}

Result dfs(vector<int> graph[], bool tmp_visited[], bool visited[], int node, int a) {
	Result response;
	response.error = false;

//	for(int x = 0; x < a; x++) printf("  ");
//	printf("Nó visitado: %d (%s)\n", node, names_rev[node].c_str());

	if (visited[node] == true && tmp_visited[node] == false) {
		/* Se já visitamos o subgrafo antes, então ele não é ciclico e já foi adicionado a lista de nomes previamente */
		return response;

	} else if (tmp_visited[node] == true) {
		/* Estamos visitando pela segunda vez em uma chamada. Logo, temos um grafo cíclico. Não convém. */
		response.error = true;
		return response;

	} else {
		/* Marcamos que o grafo já foi visitado (tanto nessa chamada, quanto nas chamadas gerais). */
		tmp_visited[node] = true;

	}

	while(graph[node].empty() == false) {
		Result dfs_response = dfs(graph, tmp_visited, visited, graph[node].back(), a+1);
		graph[node].pop_back();	

		if (dfs_response.error == true) {
			response.error = true;
			break;

		} else {
			response.ns.insert(response.ns.end(), dfs_response.ns.begin(), dfs_response.ns.end());
		}
	}

	tmp_visited[node] = false;
	visited[node] = true;

	/* Se estiver tudo ok, inserimos o nó no final (adicionamos os amigos necessários para ele e então ele). Se não estiver ok, isso será ignorado pelo [error = true]. */
	response.ns.push_back(node);

	return response;
}

int main() {
	int a, b, c, d, e, t;
	string name, name2;
	vector<int> graph[MAX];
	bool visited[MAX], tmp_visited[MAX];

	t = 1;

	while(scanf("%d", &c), c != 0) {
		for (a = 0; a < c; a++) {
			cin >> name;
			names[name] = a;
			names_rev[a] = name;
		}

		for (a = 0; a < c; a++) {
			cin >> name;
			d = names[name];
			scanf("%d", &b);

			while(b--) {
				cin >> name2;
				e = names[name2];

				// Grafo direcionado (para ser amigo de X, antes precisa ser amigo de Y; o contrário nem sempre é verdade).
				graph[d].push_back(e);
			}
		}

		for (a = 0; a < c; a++) {
			visited[a] = false;
			tmp_visited[a] = false;
		}


		Result response;
		response.error = false;
		
		for (a = 0; a < c; a++) {
			if (visited[a] == false) {
				Result dfs_response = dfs(graph, tmp_visited, visited, a, 0);
				
				if (dfs_response.error == true) {
					response.error = true;
					break;

				} else {
					response.ns.insert(response.ns.end(), dfs_response.ns.begin(), dfs_response.ns.end());
				}
			}
		}

		printf("Teste %d\n", t++);
//		debug_printmapsi(names);
//		debug_printmapis(names_rev);

		if (response.error == true) printf("impossivel\n\n");
		else {
			vector<int>::iterator it = response.ns.begin();
			cout << names_rev[*it++];			

			for (; it != response.ns.end(); it++) {
				cout << " " << names_rev[*it];
			}
			printf("\n\n");
		}

		names.clear();
		names_rev.clear();
		for (a = 0; a < c; a++) graph[a].clear();
	}

	return 0;
}
