//GitHub.com/EnesBuyuk
//Problem: https://arsiv.cclub.metu.edu.tr/problem/22game/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t islands=1, roads, oddLinked = 0;
    cin >> islands >> roads;
    int *linked = new int[islands]();
    for (int singleIsland1, singleIsland2; roads; roads--)
    {
        cin >> singleIsland1 >> singleIsland2;
        linked[singleIsland1]++;
        linked[singleIsland2]++;
    }
    for (int i = 0; i < static_cast<int>(islands); i++) if(linked[i] % 2) oddLinked++;
    delete[] linked;
    cout << ((oddLinked == 0 || oddLinked == 2) ? "VALID" : "INVALID");
    return 0;
}
