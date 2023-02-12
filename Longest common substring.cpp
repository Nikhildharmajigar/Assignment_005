#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    int LCSLength = 0;
    int endIndex = m - 1;
    int lookup[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        lookup[i][0] = 0;
    for (int j = 0; j <= n; j++)
        lookup[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
                if (lookup[i][j] > LCSLength) {
                    LCSLength = lookup[i][j];
                    endIndex = i - 1;
                }
            }
            else
                lookup[i][j] = 0;
        }
    }
    cout << "LCS Length is: " << LCSLength << endl;
    cout << "LCS is: ";
    for (int i = endIndex - LCSLength + 1; i <= endIndex; i++)
        cout << X[i];
    return LCSLength;
}

int main() {
    string X = "ABCD";
    string Y = "ABDC";
    LCS(X, Y);
    return 0;
}
