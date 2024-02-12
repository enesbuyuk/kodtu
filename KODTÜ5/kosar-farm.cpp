//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/24kosar/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<vector<int>> farm(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> farm[i][j];
        }
    }
    vector<vector<int>> xorPrefix(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            xorPrefix[i][j] = farm[i - 1][j - 1] ^ xorPrefix[i - 1][j] ^ xorPrefix[i][j - 1] ^ xorPrefix[i - 1][j - 1];
        }
    }
    int maxFertility = 0;
    for (int i = X; i <= N; ++i) {
        for (int j = Y; j <= M; ++j) {
            int fertility = xorPrefix[i][j] ^ xorPrefix[i - X][j] ^ xorPrefix[i][j - Y] ^ xorPrefix[i - X][j - Y];
            maxFertility = max(maxFertility, fertility);
        }
    }
    cout << maxFertility;
    return 0;
}
