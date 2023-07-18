#include <iostream>
#include <vector>
using namespace std;
void floodFill(vector<vector<int>>& screen, int row, int col, int newColor, int oldColor) {
    int M = screen.size();
    int N = screen[0].size();
    if (row < 0 || row >= M || col < 0 || col >= N) {
        return;
    }
    if (screen[row][col] != oldColor) {
        return;
    }
    screen[row][col] = newColor;
    floodFill(screen, row - 1, col, newColor, oldColor);
    floodFill(screen, row + 1, col, newColor, oldColor); 
    floodFill(screen, row, col - 1, newColor, oldColor); 
    floodFill(screen, row, col + 1, newColor, oldColor); 
}
int main() {
    int M, N;
    cout << "Enter the number of rows and columns in the screen: ";
    cin >> M >> N;
    vector<vector<int>> screen(M, vector<int>(N));
    cout << "Enter the screen pixels (0 for empty, 1 for colored):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> screen[i][j];
        }
    }
    int row, col, newColor;
    cout << "Enter the row and column of the pixel: ";
    cin >> row >> col;
    cout << "Enter the new color: ";
    cin >> newColor;
    int oldColor = screen[row][col];
    floodFill(screen, row, col, newColor, oldColor);
    cout << "Updated screen:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
