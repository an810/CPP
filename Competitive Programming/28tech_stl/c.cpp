// link: https://codeforces.com/group/cGzZeXNyzp/contest/400904/problem/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t) {
        int n; cin >> n;
        int player1=0, player2=0, player3=0;
        unordered_map<string, int> words;
        unordered_map<string, bool> word_player_1, word_player_2, word_player_3;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            words[s]++;
            word_player_1[s] = true;
        }
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            words[s]++;
            word_player_2[s] = true;
        }
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            words[s]++;
            word_player_3[s] = true;
        }
        for (auto &word : words) {
            if (word_player_1[word.first]) {
                if (word.second == 1)
                    player1 += 3;
                else if (word.second == 2) 
                    player1 += 1;
            }
            if (word_player_2[word.first]) {
                if (word.second == 1)
                    player2 += 3;
                else if (word.second == 2) 
                    player2 += 1;
            }
            if (word_player_3[word.first]) {
                if (word.second == 1)
                    player3 += 3;
                else if (word.second == 2) 
                    player3 += 1;
            }
        }
        cout << player1 << " " << player2 << " " << player3 << "\n";
        t--;
    }
    return 0;
}