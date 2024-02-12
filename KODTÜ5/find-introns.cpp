//GitHub.com/EnesBuyuk
//https://arsiv.cclub.metu.edu.tr/problem/24intron/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int DNASize, mRNASize;
    cin >> DNASize >> mRNASize;
    string DNA, mRNA, convertedDNA;
    cin >> DNA >> mRNA;
    for (char cr: DNA) {
        if (cr == 'A') {
            convertedDNA += "U";
        } else if (cr == 'T') {
            convertedDNA += "A";
        } else if (cr == 'G') {
            convertedDNA += "C";
        } else if (cr == 'C') {
            convertedDNA += "G";
        }
    }
    if (mRNASize != 0) {
        for (int i = 0; i < DNASize; i++) {
            if (mRNA[i] != convertedDNA[i]) {
                for (int j = i; j < i + (DNASize - mRNASize); j++) {
                    cout << DNA[j];
                }
                break;
            }
        }
    } else {
        cout << "";
    }
    return 0;
}

