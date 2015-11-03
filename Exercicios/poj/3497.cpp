#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1005
#define INF 1000000005

typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
	
	int t, n, b, quality, price, i, j, LOW, HIGH, MED, COST, MONEY, K;
	string type, useless;
	bool worked;

	cin >> t;

	while(t--) {
		map<string, int> mapa;
		vector<pii> types[MAX];
		map<string, int>::iterator item;

		cin >> n >> b;
		K = 0;

		while(n--) {
			cin >> type >> useless >> price >> quality;

			if (price > b) continue;

			item = mapa.find(type);
			if (item != mapa.end())
				j = item->second;
			else {
				mapa[type] = K;
				j = K++;
			}

			types[j].push_back(pii(quality, price));
		}

		LOW = 0, HIGH = 1000000000;

		while (LOW != HIGH) {
			MED = (LOW + HIGH + 1) / 2;
			MONEY = b;
			worked = true;

			for (i = 0; i < K; i++) {
				COST = INF;

				for (j = 0; j < types[i].size(); j++)
				 	if (types[i][j].second < COST && types[i][j].first >= MED)
						COST = types[i][j].second;

				MONEY -= COST;

				if (MONEY < 0) {
					worked = false;
					break;
				}
			}

			if (!worked)
				HIGH = MED - 1;
			else
				LOW = MED;
		}

		cout << LOW << '\n';
	}

	return 0;
}