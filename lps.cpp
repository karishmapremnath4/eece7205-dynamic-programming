#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lps(const string& s) {
    int n = s.size();
    vector<vector<int>> L(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) L[i][i] = 1;                 // one character
    for (int len = 2; len <= n; len++) {                     // by substring length
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j])
                L[i][j] = L[i + 1][j - 1] + 2;               // use both ends (L[i+1][i] = 0 when len = 2)
            else
                L[i][j] = max(L[i + 1][j], L[i][j - 1]);     // drop one end
        }
    }
    return L[0][n - 1];
}

int main() {
    cout << "BBABCBCAB: " << lps("BBABCBCAB") << endl;
    cout << "AGBDBA: " << lps("AGBDBA") << endl;
    return 0;
}
