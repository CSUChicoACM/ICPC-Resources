#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef  struct { int from; int to; int w; }  edge;
typedef  vector<list<edge>>         AdjList;


void processEdge(AdjList &graph, vector<int> &tax, edge &e1) {
    printf("%d--%d-->%d\n", e1.from, e1.w, e1.to);
    for (edge &e2 : graph[e1.to]) if (e2.to != e1.from) {
        processEdge(graph, tax, e2);
    }
}

void getDistances(AdjList &graph, vector<int> &tax) {
    edge e = {-1, 0, 0};
    processEdge(graph, tax, e);
}

int main() {
    int N, u, v, w;

    cin >> N;

    vector<int> tax(N);
    for (int &t : tax) cin >> t;

    AdjList graph(N);
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({u, v,w});
        graph[v].push_back({v, u,w});
    }

    getDistances(graph, tax);
}
