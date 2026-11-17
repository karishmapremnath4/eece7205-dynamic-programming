#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goldMine(const vector<vector<int>>& mine) {
    int m = mine.size(), n = mine[0].size();
    vector<vector<int>> gold(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) gold[i][n - 1] = mine[i][n - 1];   // last column: nowhere to go
    for (int j = n - 2; j >= 0; j--) {                             // fill from right to left
        for (int i = 0; i < m; i++) {
            int best = gold[i][j + 1];                                    // right
            if (i > 0)     best = max(best, gold[i - 1][j + 1]);          // right-up
            if (i < m - 1) best = max(best, gold[i + 1][j + 1]);          // right-down
            gold[i][j] = mine[i][j] + best;
        }
    }
    int ans = gold[0][0];
    for (int i = 1; i < m; i++) ans = max(ans, gold[i][0]);       // best starting row
    return ans;
}

int main() {
    vector<vector<int>> mine1 = {{1, 3, 3},
                                 {2, 1, 4},
                                 {0, 6, 4}};
    vector<vector<int>> mine2 = {{1, 3, 1, 5},
                                 {2, 2, 4, 1},
                                 {5, 0, 2, 3},
                                 {0, 6, 1, 2}};
    cout << "mine 1: " << goldMine(mine1) << endl;
    cout << "mine 2: " << goldMine(mine2) << endl;
    return 0;
}
