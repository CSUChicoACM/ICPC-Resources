#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;


typedef vector<list<int>> AdjList;


void bfs(AdjList &graph, int start, vector<int> &distances) {
    int n = graph.size();
    vector<char> color(n, 'w');

    color[start] = 'g';
    distances[start] = 0;

    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        
        for (int to : graph[cur]) if (color[to] == 'w') {
            Q.push(to);
            color[to] = 'g';
            distances[to] = distances[cur]+1;
        }

        color[cur] = 'b';
    }
}


int main() {

    int N, M, a, b;
    cin >> N >> M;

    AdjList graph(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--; // indexes start at 0
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distances(N, INT_MAX);
    bfs(graph, 0, distances);
    cout << distances[N-1]-1 << endl;
}
