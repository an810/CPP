// link: https://codeforces.com/group/cGzZeXNyzp/contest/433846/problem/B3
#include<bits/stdc++.h>
using namespace std;

int countWords(string str) {
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : str) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }
    if (inWord) {
        wordCount++;
    }
    
    return wordCount;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignore newline character after t
    
    for (int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        int wordCount = countWords(line);
        cout << wordCount << endl;
    }
    
    return 0;
}
