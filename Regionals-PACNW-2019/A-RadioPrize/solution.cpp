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
        printf("%d->%d: ", cur, e.to);
        for (int s : seen) {
            int w = distances[cur][s] + e.w;
            printf("{%d,%d,%d} ", s, e.to, w);
            distances[s][e.to] = w;
            distances[e.to][s] = w;
        }
        printf("\n");
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

    for (int i = 0; i < N; i++) {
        printf("%d: ", i);
        for (edge &e : graph[i]) printf("{%d,%d} ", e.to, e.w);
        printf("\n");
    }

    Matrix distances;
    getDistances(graph, distances);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", distances[i][j]);
        printf("\n");
    }

}
