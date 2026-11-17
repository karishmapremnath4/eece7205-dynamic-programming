#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane on a[0..m-1]; also reports where the best block starts and ends
int kadane(const vector<int>& a, int& top, int& bottom) {
    int cur = a[0], best = a[0], start = 0;
    top = bottom = 0;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] > cur + a[i]) { cur = a[i]; start = i; }   // restart at i
        else cur = cur + a[i];                              // extend
        if (cur > best) { best = cur; top = start; bottom = i; }
    }
    return best;
}

int main() {
    vector<vector<int>> A = {{ 1,  2, -1, -4, -20},
                             {-8, -3,  4,  2,   1},
                             { 3,  8, 10,  1,   3},
                             {-4, -1,  1,  7,  -6}};
    int m = A.size(), n = A[0].size();
    int best = INT_MIN, bl = 0, br = 0, bt = 0, bb = 0;
    for (int l = 0; l < n; l++) {
        vector<int> rowSum(m, 0);
        for (int r = l; r < n; r++) {
            for (int i = 0; i < m; i++) rowSum[i] += A[i][r];   // add column r only
            int top, bottom;
            int s = kadane(rowSum, top, bottom);
            if (s > best) { best = s; bl = l; br = r; bt = top; bb = bottom; }
        }
    }
    cout << "max sum: " << best << endl;
    cout << "top-left (" << bt << ", " << bl << "), bottom-right (" << bb << ", " << br << ")" << endl;
    return 0;
}
