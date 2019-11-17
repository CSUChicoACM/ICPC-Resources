#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<char>> Maze;


void print_line(vector<char> &v) {
    for (char &c : v) cout << c;
    cout << endl;
}

int main() {
    int R, C;
    cin >> R >> C;

    Maze maze;
    maze.resize(R);

    for (int r = 0; r < R; r++) {
        maze[r].resize(C);
        for (int c = 0; c < C; c++) cin >> maze[r][c];
    }

    for (auto &v : maze) print_line(v);
}
