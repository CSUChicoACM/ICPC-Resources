#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef  struct {
    int from;
    int to;
    int w;
    int nn;  // number of nodes
    int ttm; // total tax multiplier
    int tel; // total edge length
    int ttr; // total tax returned
}  edge;

typedef vector<list<edge>> AdjList;


void processEdge(AdjList &graph, vector<int> &tax, edge &e1) {
    if (e1.tel != -1) return;

    e1.nn = e1.ttm = e1.tel = e1.ttr = 0;
    for (edge &e2 : graph[e1.to]) if (e2.to != e1.from) {
        processEdge(graph, tax, e2);
        e1.nn  += e2.nn;
        e1.ttm += e2.ttm;
        e1.tel += e2.tel;
        e1.ttr += e2.ttr;
    }

    e1.nn  += 1;
    e1.ttm += tax[e1.to];
    e1.tel += e1.nn  * e1.w;
    e1.ttr += e1.ttm * e1.w;

    printf("%d--%d-->%d\n", e1.from, e1.w, e1.to);
    printf("ttm:%d\ntel:%d\nttr:%d\nnn:%d\n----------------\n\n", e1.ttm, e1.tel, e1.ttr, e1.nn);
}

void getDistances(AdjList &graph, vector<int> &tax) {
    for (int i = 0; i < graph.size(); i++) {
        edge e = {-1, i, 0, -1, -1, -1, -1};
        processEdge(graph, tax, e);
        printf("======\n%d\n======\n\n\n", e.ttr + (e.tel*tax[i]));
    }
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
        graph[u].push_back({u, v, w, -1, -1, -1, -1});
        graph[v].push_back({v, u, w, -1, -1, -1, -1});
    }

    getDistances(graph, tax);
}
