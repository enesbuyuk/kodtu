//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/24mysticmove/
#include <bits/stdc++.h>
using namespace std;
int minOperation(int a, int b, const string& firstWord, const string& secondWord) {
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (firstWord[i - 1] == secondWord[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[a][b];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    string firstWord, secondWord;
    cin >> firstWord >> secondWord;
    int result = minOperation(a, b, firstWord, secondWord);
    cout << result << endl;
    return 0;
}
