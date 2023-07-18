#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Cell {
    int row;
    int col;
    int time;
    Cell(int r, int c, int t) : row(r), col(c), time(t) {}
};
bool isValidCell(int row, int col, int M, int N) {
    return (row >= 0 && row < M && col >= 0 && col < N);
}
int minTimeToRotOranges(vector<vector<int>>& grid) {
    int M = grid.size(); 
    int N = grid[0].size();
    queue<Cell> rottenQueue;
    int freshCount = 0;
    int minTime = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 2) {
                rottenQueue.push(Cell(i, j, 0));
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }
    while (!rottenQueue.empty()) {
        Cell curr = rottenQueue.front();
        rottenQueue.pop();
        minTime = curr.time;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + dx[i];
            int newCol = curr.col + dy[i];
            if (isValidCell(newRow, newCol, M, N) && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2;
                rottenQueue.push(Cell(newRow, newCol, curr.time + 1));
                freshCount--;
            }
        }
    }
    if (freshCount > 0) {
        return -1;
    }

    return minTime;
}
int main() {
    int M, N;
    cout << "Enter the number of rows and columns: ";
    cin >> M >> N;
    vector<vector<int>> grid(M, vector<int>(N));
    cout << "Enter the matrix (0 for empty, 1 for fresh, 2 for rotten):\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int minTime = minTimeToRotOranges(grid);
    if (minTime == -1) {
        cout << "It is impossible to rot every orange.\n";
    } else {
        cout << "Minimum time required to rot all oranges: " << minTime << endl;
    }

    return 0;
}
