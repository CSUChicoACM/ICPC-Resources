#include <iostream>
#include <vector>
using namespace std;


typedef vector<vector<char>> Maze;


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

int main() {
    int R, C;
    Maze maze;

    cin >> R >> C;
    readMaze(maze, R, C);

    printMaze(maze);
}
