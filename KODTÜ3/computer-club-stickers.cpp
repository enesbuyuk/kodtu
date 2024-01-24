//GitHub.com/EnesBuyuk
//Problem: https://arsiv.cclub.metu.edu.tr/problem/22sticker/
#include <iostream>
using namespace std;
int main() {
    unsigned short int N, M;
    cin >> N >> M;
    cout << static_cast<unsigned int>(N - 1) * M + (M - 1) * N << endl;
}
