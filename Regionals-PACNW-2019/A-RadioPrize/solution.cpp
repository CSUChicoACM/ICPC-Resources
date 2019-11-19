#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef struct { int to; int w; } edge;
typedef vector<list<edge>> AdjList;


void dfsVisit(AdjList &graph, vector<char> &color, int cur, int depth) {
    for (int i = 0; i < depth; i++) printf("  "); printf("%d\n", cur);
    color[cur] = 'g';
    for (edge &e : graph[cur]) if (color[e.to]=='w') {
        dfsVisit(graph, color, e.to, depth+1);
    }
    color[cur] = 'b';
}

void dfs(AdjList &graph) {
    vector<char> color(graph.size(), 'w');
    dfsVisit(graph, color, 0, 0);
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

    dfs(graph);
}
