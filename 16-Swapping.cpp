#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minSwapsToSort(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arrPos(n);
    for (int i = 0; i < n; i++) {
        arrPos[i] = make_pair(arr[i], i);
    }
    sort(arrPos.begin(), arrPos.end());

    vector<bool> visited(n, false);
    int minSwaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arrPos[i].second == i) {
            continue;
        }
        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycleSize++;
        }
        if (cycleSize > 0) {
            minSwaps += (cycleSize - 1);
        }
    }
    return minSwaps;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minSwaps = minSwapsToSort(arr);
    cout << "Minimum number of swaps required to sort the array: " << minSwaps << endl;

    return 0;
}
