//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/21triangle/
#include <bits/stdc++.h>
using namespace std;
double calculateAngle(double x1, double y1, double x2, double y2) {
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;
    double angle = std::atan2(deltaY, deltaX);
    if (angle < 0.0) angle += 2.0 * M_PI;
    angle = angle * 180.0 / M_PI;
    return angle;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int lines;
    cin >> lines;
    vector<vector<double>> triangles;
    int x,y;
    for(int i=0,a,b;lines--;i++){
        i==0 ? (cin >> x >> y):(cin >> a >> b);
        vector<double> subset;
        subset.emplace_back(i);
        if(i==0){subset.emplace_back(0);}else{subset.emplace_back(calculateAngle(x,y,a,b));}
        triangles.emplace_back(subset);
    }
    cout << triangles[0][0]+1 << " ";
    triangles.erase(triangles.begin());
    sort(triangles.begin(), triangles.end(), [](const vector<double>& a, const vector<double>& b) {
        return a[1]>b[1];
    });
    cout << triangles[0][0]+1 << " " << triangles[1][0]+1 << " ";
    return 0;
}
