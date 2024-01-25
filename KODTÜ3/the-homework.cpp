//GitHub.com/EnesBuyuk
//Problem: https://arsiv.cclub.metu.edu.tr/problem/22homework/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main() {
    int length;
    cin >> length;
    cin.ignore();
    vector<string> firstVector, secondVector;
    for (int i = 0; i < length; i++) {
        string firstInput, secondInput;
        getline(cin, firstInput);
        getline(cin, secondInput);
        firstVector.emplace_back(firstInput);
        secondVector.emplace_back(secondInput);
    }
    for (int i = 0; i < length; i++) {
        vector<string>  firstVectorsWords, secondVectorsWords, longestCommonWords;
        string firstVectorsWord,secondVectorsWord;
        int commonWordCount = 0;
        istringstream SSfirstVectorsWords(firstVector[i]),SSsecondVectorsWords(secondVector[i]);
        while(SSfirstVectorsWords >> firstVectorsWord) {
            firstVectorsWords.push_back(firstVectorsWord);
        }
        while(SSsecondVectorsWords >> secondVectorsWord) {
            secondVectorsWords.push_back(secondVectorsWord);
        }
        for (size_t j = 0; j < firstVectorsWords.size(); ++j) {
            for (size_t k = 0; k < secondVectorsWords.size(); ++k) {
                size_t m = j, n = k;
                std::vector<std::string> current;
                while (m < firstVectorsWords.size() && n < secondVectorsWords.size() &&
                       firstVectorsWords[m] == secondVectorsWords[n]) {
                    current.push_back(firstVectorsWords[m]);
                    ++m;
                    ++n;
                }
                if (current.size() > longestCommonWords.size()) longestCommonWords = current;
            }
        }
        for(string w : longestCommonWords) commonWordCount++;
        cout<<commonWordCount<<endl;
    }
    return 0;
}
