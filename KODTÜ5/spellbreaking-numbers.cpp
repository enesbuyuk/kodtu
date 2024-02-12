//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/24spellbreaking/
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int loop;
    cin >> loop;
    while(loop--){
        long int a,b,c;
        cin >> a >> b >> c;
        bool result = ((a - b == c) || (b - a == c) || (a + b == c) || (b * a == c));
	cout << result << "\n";
    }
    return 0;
}
