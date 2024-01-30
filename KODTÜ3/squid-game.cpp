//GitHub.com/EnesBuyuk
//Problem: https://arsiv.cclub.metu.edu.tr/problem/22marbles/
#include <iostream>
#include <vector>
using namespace std;
bool findTF(int const& x, int const& y, vector<int>& calculatedFalseValues, int& notFound, int& diff) {
    calculatedFalseValues.insert(calculatedFalseValues.end(), {0,2,1});
    if (x == 0) return y != 0;
    if (x == 1) return y != 2;
    if (calculatedFalseValues[x] != 0) return y != calculatedFalseValues[x];
    for(int j=notFound;j<=x;j++){
        if(calculatedFalseValues[j]!=0) continue;
        calculatedFalseValues[j]=j+diff;
        calculatedFalseValues[j+diff]=j;
        diff++;
        if((j+diff-1)==x){
            notFound = (calculatedFalseValues[j+1]==0) ? j+1:j+2;
            return true;
        }
    }
    notFound = (calculatedFalseValues[x+1]==0) ? x+1:x+2;
    return y != calculatedFalseValues[x];
}
int main() {
    int numberofMatches, notFound = 3, diff = 2;
    vector<int> calculatedFalseValues(850000);
    cin >> numberofMatches;
    while (numberofMatches--) {
        int firstPile, secondPile;
        cin >> firstPile >> secondPile;
        firstPile<secondPile ? (findTF(firstPile,secondPile,calculatedFalseValues, notFound, diff) ? cout << "T" << endl : cout << "F" << endl):(findTF(secondPile, firstPile, calculatedFalseValues, notFound, diff) ? cout << "T" << endl : cout << "F" << endl);
    }
    return 0;
}
