#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& grid, int row, int col, int M, int N) {
    if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != 1) {
        return;
    }
    grid[row][col] = 0;
    dfs(grid, row - 1, col, M, N); 
    dfs(grid, row + 1, col, M, N); 
    dfs(grid, row, col - 1, M, N); 
    dfs(grid, row, col + 1, M, N); 
}
int countIslands(vector<vector<int>>& grid) {
    int M = grid.size(); 
    int N = grid[0].size(); 
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j, M, N);
                count++;
            }
        }
    }
    return count;
}
int main() {
    int M, N;
    cout << "Enter the number of rows and columns in the matrix: ";
    cin >> M >> N;
    vector<vector<int>> grid(M, vector<int>(N));
    cout << "Enter the matrix elements (0 for water, 1 for land):\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    int islandCount = countIslands(grid);
    cout << "Number of islands: " << islandCount << endl;
    return 0;
}
