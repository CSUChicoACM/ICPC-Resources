#include <iostream>
#include <vector>
#include <list>
using namespace std;


typedef vector<vector<char>> Maze;
typedef vector<list<int>> AdjList;


// linear time but that's ok
void push_front(vector<char> &v, char c) {
    v.resize(v.size()+1);
    for (int i = v.size()-1; i; i--) v[i] = v[i-1];
    v[0] = c;
}

void dfsVisit(AdjList &graph, int cur, vector<int> &color) {
    color[cur] = 'g';
    for (int to : graph[cur]) if (color[to]=='w') dfsVisit(graph, to, color);
    color[cur] = 'b';
}

int numSCC(AdjList &graph) {
    int n = graph.size();
    vector<int> color(n, 'w');
    int total = 0;

    for (int i = 0; i < n; i++) if (color[i]=='w') {
        dfsVisit(graph, i, color);
        total++;
    }
    return total;
}

void readMaze(Maze &maze, int R, int C) {
    maze.resize(R);
    for (int r = 0; r < R; r++) {
        maze[r].resize(C);
        for (int c = 0; c < C; c++) cin >> maze[r][c];
    }
}

bool isEven(Maze &maze) {
    int R = maze.size();
    int C = maze[0].size();
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char chr = maze[r][c];
            if (chr=='.') continue;
            if (chr== '/') return (r+c)%2 == 0;
            if (chr=='\\') return (r+c)%2 == 1;
        }
    }
    return true; // empty graph is even
}

void normalizeMaze(Maze &maze) {
    if (!isEven(maze))
        for (auto &row : maze) push_front(row, '.');

    if (maze[0].size() % 2 == 0)
        for (auto &row : maze) row.push_back('.');
}

AdjList getGraph(Maze &maze) {
    int R = maze.size();
    int C = maze[0].size();
    int nodesPerRow = C/2;
    int n = nodesPerRow*(R-1);
    AdjList graph(n+1);
    int node = 0;

    for (int r = 0; r < R-1; r++) {
        int start = r%2;
        for (int c = start; c < C-1; c+=2) {
            // find walls
            char nw = maze[r  ][c  ];
            char ne = maze[r  ][c+1];
            char sw = maze[r+1][c  ];
            char se = maze[r+1][c+1];

            // determine identity of adjacent nodes
            int nwn, nen, swn, sen;
            if (r%2==0) {
                nwn = r==0?n   : c==0?n   : node-nodesPerRow-1;
                nen = r==0?n   :            node-nodesPerRow;
                swn = r==R-2?n : c==0?n   : node+nodesPerRow-1;
                sen = r==R-2?n :            node+nodesPerRow;
            } else {
                nwn =                       node-nodesPerRow;
                nen =            c==C-2?n : node-nodesPerRow+1;
                swn = r==R-2?n :            node+nodesPerRow;
                sen = r==R-2?n : c==C-2?n : node+nodesPerRow+1;
            }

            // add edges where there are no walls
            if ( nwn==n && nw=='.' || nen==n && ne=='.' || 
                 swn==n && sw=='.' || sen==n && se=='.' ) {
                graph[node].push_back(n);
                graph[n].push_back(node);
            }
            if (nwn!=n && nw=='.') graph[node].push_back(nwn);
            if (nen!=n && ne=='.') graph[node].push_back(nen);
            if (swn!=n && sw=='.') graph[node].push_back(swn);
            if (sen!=n && se=='.') graph[node].push_back(sen);

            node++;
        }
    }
    return graph;
}

int main() {
    int R, C;
    Maze maze;

    cin >> R >> C;
    readMaze(maze, R, C);

    normalizeMaze(maze);

    AdjList graph = getGraph(maze);
    cout << numSCC(graph)-1 << endl;
}
