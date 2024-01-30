//GitHub.com/EnesBuyuk
//Problem: https://arsiv.cclub.metu.edu.tr/problem/22marbles/
#include <iostream>
#include <vector>
using namespace std;
bool findTF(int const& x, int const& y, vector<int>& CalculatedFalseValues, int& notFound, int& diff) {
    CalculatedFalseValues.insert(CalculatedFalseValues.end(), {0,2,1});
    if (x == 0) return y != 0;
    if (x == 1) return y != 2;
    if (CalculatedFalseValues[x] != 0) return y != CalculatedFalseValues[x];
    for(int j=notFound;j<=x;j++){
        if(CalculatedFalseValues[j]!=0) continue;
        CalculatedFalseValues[j]=j+diff;
        CalculatedFalseValues[j+diff]=j;
        diff++;
        if((j+diff-1)==x){
            notFound = (CalculatedFalseValues[j+1]==0) ? j+1:j+2;
            return true;
        }
    }
    notFound = (CalculatedFalseValues[x+1]==0) ? x+1:x+2;
    return y != CalculatedFalseValues[x];
}
int main() {
    int numberofMatches, notFound = 3, diff = 2;
    vector<int> CalculatedFalseValues(850000);
    cin >> numberofMatches;
    while (numberofMatches--) {
        int firstPile, secondPile;
        cin >> firstPile >> secondPile;
        firstPile<secondPile ? (findTF(firstPile,secondPile,CalculatedFalseValues, notFound, diff) ? cout << "T" << endl : cout << "F" << endl):(findTF(secondPile, firstPile, CalculatedFalseValues, notFound, diff) ? cout << "T" << endl : cout << "F" << endl);
    }
    return 0;
}
