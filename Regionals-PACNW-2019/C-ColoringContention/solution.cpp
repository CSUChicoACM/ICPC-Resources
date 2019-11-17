#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


typedef vector<list<int>> AdjList;


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
}
