#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <float.h>
using namespace std;

#define Max_V 10000
#define INF DBL_MAX

vector< vector< pair<int, double> > > v(Max_V+1);
//vector<pair<int, double>> v[Max_V + 1];
vector<double> visit(Max_V + 1);
//double visit[Max_V + 1];
priority_queue<pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > pq;

void Dijkstra(int start) {
	visit[0] = 1;
	pq.push(make_pair(1.0, 0));

	while (!pq.empty()) {
		double cost = pq.top().first;
		int location = pq.top().second;
		pq.pop();

		if (visit[location] < cost)
			continue;
		for (int i = 0; i < v[location].size(); i++) {
			int loc = v[location][i].first;
			double wei = cost * v[location][i].second;
			if (visit[loc] > wei) {
				visit[loc] = wei;
				pq.push(pair<double,int>(wei, loc));
			}

		}
	}
	printf("%0.10f\n", visit[start - 1]);
	//return visit[size - 1];
}

int main() {
	int Testcase;
	cin >> Testcase;
	for (int i = 0; i < Testcase; i++) {
		int V, E;
		cin >> V >> E;

		//v = vector<vector<pair<int, double>>>(V);

		//for (int i = 0; i < Max_V; i++) {
		//	vector < pair<int, double> > el;
		//	v.push_back(el);
		//}

		for (int i = 0; i < Max_V; i++) {
			visit[i]=INF;
			v[i].clear();
		}

		int a, b;
		long double weight;
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> weight;
			v[a].push_back(make_pair(b, weight));
			v[b].push_back(make_pair(a, weight));
		}

		//for (int i = 0; i <= Max_V; i++)
		 //  visit.push_back(INF);

		Dijkstra(V);
		//printf("%0.10f\n", visit[V-1]);

	}

	return 0;

}