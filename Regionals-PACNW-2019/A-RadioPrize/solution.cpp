#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef  struct { int to; int w; }  edge;
typedef  vector<list<edge>>         AdjList;


void getDistances(AdjList &graph) {
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
    getDistances(graph);
}
