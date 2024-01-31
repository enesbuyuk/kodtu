//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/23weirdland/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int x,y;
    cin >> x;
    cin >> y;
    unsigned int constant=x/y;
    unsigned int b = x-(constant)*y, t=(constant+1)*y-x;
    if(x%y == 0){
        cout<<0;
        return 0;
    }
    b<t?cout<<b:cout<<t;
    return 0;
}
