#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<char>> Maze;


// linear time but that's ok
void push_front(vector<char> &v, char c) {
    v.resize(v.size()+1);
    for (int i = v.size()-1; i; i--) v[i] = v[i-1];
    v[0] = c;
}


void readMaze(Maze &maze, int R, int C) {
    maze.resize(R);
    for (int r = 0; r < R; r++) {
        maze[r].resize(C);
        for (int c = 0; c < C; c++) cin >> maze[r][c];
    }
}

void printMaze(Maze &maze) {
    for (auto &row : maze) {
        for (char &c : row) cout << c;
        cout << endl;
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

    if (maze[0].size() % 2 == 1)
        for (auto &row : maze) row.push_back('.');
}

int main() {
    int R, C;
    Maze maze;

    cin >> R >> C;
    readMaze(maze, R, C);

    normalizeMaze(maze);

    printMaze(maze);
}
