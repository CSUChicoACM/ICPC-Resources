#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef  struct { int to; int w; }  edge;
typedef  vector<list<edge>>         AdjList;
typedef  vector<vector<int>>        Matrix;


void dfsVisit(AdjList &graph, Matrix &distances, list<int> &seen, int cur, int parent) {
    seen.push_back(cur);
    for (edge &e : graph[cur]) if (e.to != parent) {
        for (int s : seen) {
            distances[s][e.to] = distances[cur][s] + e.w;
            distances[e.to][s] = distances[cur][s] + e.w;
        }
        dfsVisit(graph, distances, seen, e.to, cur);
    }
}

void getDistances(AdjList &graph, Matrix &distances) {
    int n = graph.size();
    distances.resize( n, vector<int>(n,0) ); // nXn matrix of zeroes
    list<int> seen;
    dfsVisit(graph, distances, seen, 0, -1);
}

int main() {
    int N, u, v, w;

    cin >> N;
    vector<int> tax(N);
    AdjList graph(N);

    for (int &t : tax) cin >> t;

    for (int i = 0; i < N-1; i++) {
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    Matrix distances;
    getDistances(graph, distances);

    for (int i = 0; i < N; i++) {
        int total = 0;
        for (int j = 0; j < N; j++)
            total += (tax[i]+tax[j]) * distances[i][j];
        printf("%d\n", total);
    }
}
